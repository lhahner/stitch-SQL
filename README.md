# stitch-data
Basic utility scripts to combine different strings out of different files to build  a 
complete source-code or make semi-structured data dynamically build. 

## Folder structure

| Directory | Description                                             |
| --------- | ------------------------------------------------------- |
| `/assets` | *Optional*: You can put you data you want to merge her. |
| `/bins`   | The constructed files it can be of any type.            |

## `stitich-sql` bash script
This script shall be used to combine different types of code into one big 
sql file.

### Options

| Directory | Description                                 |
| --------- | ------------------------------------------- |
| `-o`      | Define the output file and the output path. |
| `-v`      | Verbose mode will provide more information. |
