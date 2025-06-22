# sitich-SQL
## Contents
* 1. [Version `0.1.0`](#Version0.1.0)
* 2. [Folder structure](#Folderstructure) 
* 3. [`stitich-sql` bash script](#stitich-sqlbashscript)
	* 3.1. [Options](#Options)
	* 3.2. [Examples](#Examples)
* 4. [Version `1.0.0`](#Version1.0.0)
	* 4.1. [Ideas](#Ideas)

##  1. <a name='Version0.1.0'></a>Version `0.1.0`
Basic utility scripts to combine different strings out of different files to build  a 
complete source-code or make semi-structured data dynamically build.  

###  1.1. <a name='Folderstructure'></a>Folder structure

| Directory | Description                                             |
| --------- | ------------------------------------------------------- |
| `/assets` | *Optional*: You can put you data you want to merge her. |
| `/bins`   | The constructed files it can be of any type.            |

###  1.2. <a name='stitich-sqlbashscript'></a>`stitich-sql` bash script
This script shall be used to combine different types of code into one big  
sql file.

####  1.2.1. <a name='Options'></a>Options

| Options   | Description                                      |
| --------- | ---------------------------------------------- |
| `-o`      | Define the output file and the output path.    |
| `-i`      | Specfiy all the files that are taken as input. |

####  1.2.2. <a name='Examples'></a>Examples

`stitich-sql -o ./bins/`

##  2. <a name='Version1.0.0'></a>Version `1.0.0`
###  2.1. <a name='Ideas'></a>Ideas
If taking a look at the Archticture of a Database Management System (DBMS) like
the one from SQLite there are four essential parts:

1. Core
2. Backend
3. SQL Compiler
4. Accessories

Since this project will focus on injecting the output of SQL into a 
semi-structured data, like XML or JSON this project will 
dessamble parts of the SQL-Compiler and use them in a way that the 
parsing of the output.

The idea is to adjust SQL with some Macros that will help to directly
parse the output in a way the user wants it to be. For example:

`SELECT @element NAME FROM EMPLOYEES WHERE AGE = 18;`

The output will then be a parsed XML or JSON depending on the users prefrences:
````
    <xml>
        <Worksheet>
            <Table>
                <Row>  
                    <Cell>
                        <DataItem>
                            Lennart Hahner
                        </DataItem>
                    </Cell>
                </Row>
            </Table>
        </Worksheet>
````
So the general next target is to hide any complexity and provide a program
that will deal with the Macros and provide a more complex statement that
whenever run against a DBMS will provide a semi-structured output.

In SQLlite the SQL Statement is evaluated by tokenize the SQL text into tokens
and hand those tokens one by one to the parser. The idea is therefore to only use a 
tokenizer for macro consumption. 

The follwing should be a basic concept for the mapping approach:

````
@Worksheet {
 @Table(NAME) {
    @Row {
     SELECT 
        @Cell NAME, 
        @Cell AGE 
    FROM EMPLOYEES WHERE AGE > 2;
  }
 }
}
```` 

possible output:

`````
WITH STATEMENT(CONTENT) AS (
SELECT <Cell><Data>|| NAME ||</Data></Cell> FROM EMPLOYEES WHERE AGE > 2;
)
SELECT '<Worksheet>' FROM SYSIBM.SYSDUMMY;
    UNION ALL
SELECT '<Table>' FROM SYSIBM.SYSDUMMY
    UNION ALL
SELECT '<Row>' FROM SYSIBM.SYSDUMMY
    UNION ALL
SELECT CONTENT FROM STATEMENT;
    UNION ALL
SELECT '</Row></Worksheet></Table>' FROM SYSIBM.SYSDUMMY;
``````

