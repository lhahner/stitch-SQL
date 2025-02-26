# !/bin/bash
# declares the tables to compare
declare table_1=$1 
declare table_2=$2

# create file
if [[ -f ./bins/"$table_1"-"$table_2".sql ]]; then
    echo $(date) - File already exists.
else
    touch ./bins/"$table_1"-"$table_2".sql
fi

file_created=0
while [[ file_created -eq 0 ]]
do
    # Append now basic structure
    if [[ -f ./assets/excel-head.txt ]]; then
        file_created=1
        cat ./assets/excel-head.txt > ./bins/"$table_1"-"$table_2".sql
    else
        touch ./assets/excel-head.txt
    fi
done

# select table
construct_select_keys="
SELECT_KEYS AS (
  SELECT
    TC.CONSTNAME
    , TC.TBCREATOR
    , TC.TBNAME
    , TC.TYPE
    , KC.COLNAME
    , KC.COLSEQ
  FROM
    SYSIBM.SYSTABCONST TC
    INNER JOIN SYSIBM.SYSKEYCOLUSE KC
  ON TC.CONSTNAME = KC.CONSTNAME
  AND TC.TBNAME = KC.TBNAME
  WHERE
    TC.TBCREATOR IN ('PST', 'OKT')
    AND TC.TBNAME IN ('"$table_1"', '"$table_2"')
  ORDER BY
    TC.TBNAME
    , KC.COLSEQ
),"
# append to SQL file
echo $construct_select_keys >> ./bins/"$table_1"-"$table_2".sql

# select muster
construct_select_muster="
SELECT_MUSTER AS (
  SELECT
    T.TBCREATOR
    , T.TBNAME
    , T.NAME
    , T.COLTYPE
    , T.LENGTH
    , T.NULLS
    , CASE
      WHEN EXISTS (
        SELECT
          1
        FROM
          SELECT_KEYS SK
        WHERE
          T.TBCREATOR = SK.TBCREATOR
          AND T.TBNAME = SK.TBNAME
          AND T.NAME = SK.COLNAME
      )
      THEN 'PRIMKEY'
      ELSE '-'
    END AS KEY
  FROM
    SYSIBM.SYSCOLUMNS T
  WHERE
    T.TBCREATOR IN ('PST', 'OKT')
    AND T.TBNAME IN ('"$table_1"', '"$table_2"')
  ORDER BY
    T.TBNAME
    , T.NAME
),"
# append to SQL-file
echo $construct_select_muster >> ./bins/"$table_1"-"$table_2".sql

# Append now body with mapped sql statement structure
if [[ -f ./assets/excel-body.txt ]]; then
    cat ./assets/excel-body.txt >> ./bins/"$table_1"-"$table_2".sql
else
    touch ./assets/excel-body.txt
    echo $(date) - Body file does not exist, created but filled not with content.
fi

# Append now footer with mapped sql statement structure
if [[ -f ./assets/excel-footer.txt ]]; then
    cat ./assets/excel-footer.txt >> ./bins/"$table_1"-"$table_2".sql
else
    touch ./assets/excel-footer.txt
    echo $(date) - Footer file does not exist, created but filled not with content.
fi