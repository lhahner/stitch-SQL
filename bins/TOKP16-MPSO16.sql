WITH HEAD (CONTENT) AS (
SELECT '<?xml version="1.0" encoding="UTF-8"?><?mso-application progid="Excel.Sheet"?>
  <Workbook xmlns="urn:schemas-microsoft-com:office:spreadsheet"
      xmlns:o="urn:schemas-microsoft-com:office:office"
      xmlns:x="urn:schemas-microsoft-com:office:excel"
      xmlns:ss="urn:schemas-microsoft-com:office:spreadsheet"
      xmlns:html="http://www.w3.org/TR/REC-html40">
      <DocumentProperties xmlns="urn:schemas-microsoft-com:office:office">
          <Author>Accenture Technology amp; Co KG</Author>
      </DocumentProperties>
      <Styles>
          <Style ss:ID="red">
              <Interior ss:Color="#f21d4f" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="orange">
              <Interior ss:Color="#FFC000" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="yellow">
              <Interior ss:Color="#f2d91d" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="green">
              <Interior ss:Color="#4fd972" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="grey">
              <Interior ss:Color="#808080" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="blue">
              <Interior ss:Color="#4A90E2" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="Heading">
              <Font ss:Size="16" ss:Color="#000000" ss:Bold="1" />
          </Style>
          <Style ss:ID="subheading">
              <Font ss:Size="14" ss:Color="#000000" ss:Bold="1" />
              <Interior ss:Color="#00B0F0" ss:Pattern="Solid" />
          </Style>
          <Style ss:ID="subsubheading">
              <Font ss:Size="12" ss:Color="#000000" ss:Bold="1" />
          </Style>
          <Style ss:ID="content">
              <Font ss:Size="8" ss:Color="#000000" ss:Bold="0" />
          </Style>
      </Styles>'
FROM SYSIBM.SYSDUMMY1
),
SELECT_KEYS AS ( SELECT TC.CONSTNAME , TC.TBCREATOR , TC.TBNAME , TC.TYPE , KC.COLNAME , KC.COLSEQ FROM SYSIBM.SYSTABCONST TC INNER JOIN SYSIBM.SYSKEYCOLUSE KC ON TC.CONSTNAME = KC.CONSTNAME AND TC.TBNAME = KC.TBNAME WHERE TC.TBCREATOR IN ('PST', 'OKT') AND TC.TBNAME IN ('TOKP16', 'MPSO16') ORDER BY TC.TBNAME , KC.COLSEQ ),
SELECT_MUSTER AS ( SELECT T.TBCREATOR , T.TBNAME , T.NAME , T.COLTYPE , T.LENGTH , T.NULLS , CASE WHEN EXISTS ( SELECT 1 FROM SELECT_KEYS SK WHERE T.TBCREATOR = SK.TBCREATOR AND T.TBNAME = SK.TBNAME AND T.NAME = SK.COLNAME ) THEN 'PRIMKEY' ELSE '-' END AS KEY FROM SYSIBM.SYSCOLUMNS T WHERE T.TBCREATOR IN ('PST', 'OKT') AND T.TBNAME IN ('TOKP16', 'MPSO16') ORDER BY T.TBNAME , T.NAME ),
WORKSHEET_VOKP21_STURC_BODY (CONTENT, COUNT) AS (
  SELECT DISTINCT
    '<Row>' 
    || '<Cell><ss:Data ss:Type="String">' || T1.TBCREATOR || '</ss:Data></Cell>' 
    || '<Cell><ss:Data ss:Type="String">' || T1.TBNAME || '/' || T2.TBNAME 
    || '</ss:Data></Cell>' || '<Cell' || 
    CASE
      WHEN
        TRIM(T1.COLTYPE) != TRIM(T2.COLTYPE)
        AND T1.LENGTH != T2.LENGTH
        AND T1.NULLS != T2.NULLS
        AND T1.KEY != T2.KEY
      THEN ' ss:StyleID="red"'
      WHEN (
        TRIM(T1.COLTYPE) != TRIM(T2.COLTYPE)
        AND T1.LENGTH != T2.LENGTH
        AND T1.NULLS != T2.NULLS
      )
      OR (
        TRIM(T1.COLTYPE) != TRIM(T2.COLTYPE)
        AND T1.LENGTH != T2.LENGTH
        AND T1.KEY != T2.KEY
      )
      OR (
        T1.LENGTH != T2.LENGTH
        AND T1.KEY != T2.KEY
        AND T1.NULLS != T2.NULLS
      )
      OR (
        TRIM(T1.COLTYPE) != TRIM(T2.COLTYPE)
        AND T1.KEY != T2.KEY
        AND T1.NULLS != T2.NULLS
      )
      THEN ' ss:StyleID="orange"'
      WHEN
        (TRIM(T1.COLTYPE) != TRIM(T2.COLTYPE))
        OR (T1.LENGTH != T2.LENGTH)
        OR (T1.NULLS != T2.NULLS)
        OR (T1.KEY != T2.KEY)
      THEN ' ss:StyleID="yellow"'
      ELSE ' ss:StyleID="green"'
    END || '><ss:Data ss:Type="String">' || T1.NAME || '</ss:Data></Cell>' 
    || '<Cell><ss:Data ss:Type="String">' || TRIM(T1.COLTYPE) || '/' || TRIM(T2.COLTYPE) 
    || '</ss:Data></Cell>' || '<Cell><ss:Data ss:Type="String">' || T1.LENGTH || '/' 
    || T2.LENGTH || '</ss:Data></Cell>' || '<Cell><ss:Data ss:Type="String">' || T1.NULLS 
    || '/' || T2.NULLS || '</ss:Data></Cell>' || '<Cell><ss:Data ss:Type="String">' 
    || T1.KEY || '/' || T2.KEY || '</ss:Data></Cell></Row>' AS ROW_DATA
    , ROW_NUMBER() OVER (
      ORDER BY
        T1.TBCREATOR
        , T1.TBNAME
        , T1.NAME
    ) AS ROW_NUM
  FROM
    SELECT_MUSTER T1
    INNER JOIN SELECT_MUSTER T2
  ON T1.TBNAME != T2.TBNAME
  AND SUBSTR(T1.TBNAME, 5, 2) = SUBSTR(T2.TBNAME, 5, 2)
  AND T1.NAME = T2.NAME
  WHERE
    T1.TBCREATOR LIKE 'OKT%'
),WORKSHEET_FOOTER (CONTENT)
    AS (
        SELECT '</Table></Worksheet>'
        FROM SYSIBM.SYSDUMMY1
)
SELECT CONTENT
    FROM WORKSHEET_VOKP21_STURC_BODY
UNION ALL
SELECT * 
    FROM SELECT_MUSTER
UNION ALL
SELECT *
    FROM SELECT_KEYS