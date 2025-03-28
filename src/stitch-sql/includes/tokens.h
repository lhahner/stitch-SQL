#ifndef TOKENS_H
#define TOKENS_H

#define EXCEL

/**
 * @brief The Token with a required name, identified with macros
 * depending on the expected ouput mapping.
 */
typedef struct Token{
    char* name;
    int tokenType;
    int len; 
} token;

// Default Tokens
#define TK_COMMENT          0
#define TK_ID               1
#define TK_SKIP             2

#ifdef EXCEL
    #define TK_WORKSHEET    3
    #define TK_TABLE        4
    #define TK_ROW          5
    #define TK_CELL         6
// Not final check again...
    token tokens[] = {
        {"Worksheet", TK_WORKSHEET, 9},
        {"Table",     TK_WORKSHEET, 5},
        {"Row",       TK_WORKSHEET, 3},
        {"Cell",      TK_WORKSHEET, 4}
    };
#elif SOAP
    // ... TODO
#elif HTML
    // ... TODO
#elif SVG
    // ... TODO
#elif XBRL
    // ... TODO
#endif

#endif