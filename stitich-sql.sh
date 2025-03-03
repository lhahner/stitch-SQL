#!/bin/bash
set -e 
# declare list for parameters sitich-sql -i fileA fileB fileC fileD -o path-oupt
declare -a args=($*)

# declare argument counter
declare -a argc=($#)

# strings from input file
declare strings

# output flag, can be n,c,f -> none,console,file
declare output_flag=f

# output path and file where to write to
declare output_path

# counter for arguments list
declare c

# Display help information using --help
print_help() {
  cat << EOF 
  sitich-sql is a derivived version of sititch-data which focuses on concat SQLs.
  Options:
      - i : Specify input file path, e.g.: sitich-sql -i head.xml
      - o : Specify ouput path, e.g.: sitich-sql -o ./bins/head-con.xml -i head.xml 
      - f : Write output to file, path needed. e.g.: sitich-sql -f -o ./bins/head-con.xml -i head.xml TODO
      - n : Write output to console stdout. e.g.: sitich-sql -n -i head.xml TODO
EOF
exit 0;
}

# removes all temporary files
cleanup(){
  rm -f .tmp.swp
}

# print the script name and all arguments to stderr
yell() { 
    echo "$0: $*" >&2; 
}

# does the same as yell, but exits with a non-0 exit status, which means “fail”.
die() { 
    yell "$*"; exit 111;
}

# uses the || (boolean OR), which only evaluates the right side if the left one failed. 
try() { 
  "$@" || die "cannot $*"; 
}

# error-handling for no arguments
if [ $argc -eq 0 ]
then
  yell 
  echo $(date) - no arguments provided.
  exit 1
fi;

# print help and exit
if [ "${args[0]}" = "--help" ] || [ "${args[0]}" = "-h" ] || [ "${args[0]}" = "--h" ]
then
  print_help
fi

# Iteartion over all arguments passed by the user
for s in ${args[@]}
do 
  c=$(($c+1))
# Creation and error-handling for the output file
  if [ "$s" = "-o" ]
  then
    if [[ -z ${args[($s+1)]} ]]
    then
      echo ${strings[@]}
    else
      output_path=${args[($s+1)]}
      touch ${args[($s+1)]}
    fi
  fi

# input files which context will be combined
if [ "$s" = "-input" ]
then
  touch .tmp.swp
    if [[ -z ${args[($s+1)]} ]]
    then
      yell
      echo "$(date) - missing input directory."
      exit 1
    else
    # loop over arguments after -i 
      j=$c
      while [ ! -z ${args[($j)]} ]
      do
        cat ${args[($j)]} >> .tmp.swp
        j=$(($j+1))
      done 
    fi
fi
done

# Writes output to file
if [[ "$output_flag" = "f" ]]
then
  cat .tmp.swp >> $output_path
fi
cleanup



