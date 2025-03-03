#!/bin/bash
set -e 
# declare list for parameters sitich-sql -i fileA fileB fileC fileD -o path-oupt
declare -a args=($*)

# declare argument counter
declare -a argc=${#args[@]}

# Display help information using --help
print_help() {
  cat << EOF 
  sitich-sql is a derivived version of sititch-data which focuses on concat SQLs.
  Options - Required:
      - i : Specify input file path, e.g.: sitich-sql -i head.xml
      - o : Specify ouput path, e.g.: sitich-sql -i head.xml -o ./bins/head-con.xml
EOF
exit 0;
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

# print help and exit
if [ "${args[0]}" = "--help" ] || [ "${args[0]}" = "-h" ] || [ "${args[0]}" = "--h" ]; then
  print_help
fi

for i in args
do 
  echo "$i"
done

# option -i and -o have to be specfied


