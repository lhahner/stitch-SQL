/**========================================================================
 * 2025 March 25
 * 
 * Tokenizer for different SQL classes and mapping approaches.
 *========================================================================**/
#include "includes/tokenizer.h"
#include "includes/tokens.h"

#define     AT_KEYW0            1  /* Starting with @ */
#define     AT_KEYW             2  /* Following @ */
#define     AT_WORD             3  /* Words of alphabetic nature */
#define     AT_OBRACKET         4  /* ( */
#define     AT_CBRACKET         5  /* ) */
#define     AT_OCBRACKET        6  /* { */
#define     AT_CCBRACKET        7  /* } */
#define     AT_MINUS            8  /* - */
#define     AT_ILLEGAL          9  /* Illegal character */
#define     AT_NUL              10  /* null or not important */
#define     AT_SPACE            11 /* Space */
#define     AT_NUM              12 /* Numeric */
#define     AT_COMMENT          13 /* Comments */

// Define here the ASCII Code for the different Keywords.
#ifdef STITCHSQL_ASCII
const char stitchSQL_ASCII[] = {
/*        x0  x1 x2 x3 x4 x5 x6 x7 x8 x9 xa xb xc xd xe xf */
/* 0x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 1x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 2x */   9, 9, 9, 9, 9, 9, 9, 9, 4, 5, 9, 9, 9, 8, 9, 9,
/* 3x */   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9,
/* 4x */   1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
/* 5x */   3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,10,10,10,10, 3,
/* 6x */  10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
/* 7x */   3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 9, 7,10,10,
/* 8x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 9x */   9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ax */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9,
/* Bx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Cx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Dx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ex */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
};
#elif STITCHSQL_EBCDIC
// TOOD
#endif

unsigned int stitchSQL_getTokenClass(unsigned char **pz, size_t size) {
    unsigned char* z = *pz;
    int t;
    for(int i = 0; i<size/sizeof(char*); i++){
        stitchSQL_getToken(z, &t); 
        pz++;
        z = *pz;
    }
    return t; // Class result for z
}

int stitchSQL_getToken(const unsigned char *z, int* tokenType){
    int i = 0, c;
    switch(stitchSQL_ASCII[*z]){
        case AT_MINUS: {
            if(z[1]=='-'){
                for(i=2; c!=0&&c!='\n';i++){
                    c = z[i];
                }
                *tokenType = TK_COMMENT;
                return i;
            }
            else {
                *tokenType = TK_SKIP;
            }
        }
        case AT_KEYW0: {
            for(; stitchSQL_ASCII[z[i]]<AT_OBRACKET; i++){
                if(stitchSQL_ASCII[z[1]]>AT_KEYW) {
                    *tokenType = TK_SKIP;
                    return -1;
                }    
            }
            *tokenType = AT_KEYW;
            return i;
        }
        case AT_OBRACKET: {
            *tokenType = AT_OBRACKET;
            return 1;
        }
        case AT_CBRACKET: {
            *tokenType = AT_CBRACKET;
            return 1;
        }
        case AT_OCBRACKET: {
            *tokenType = AT_OCBRACKET;
            return 1;
        }
        case AT_CCBRACKET: {
            *tokenType = AT_CCBRACKET;
            return 1;
        }
        case AT_NUL: {
            i++;
        }
        case AT_SPACE: {
            i++;
        }
        default : {
            *tokenType = AT_ILLEGAL;
            return -1;
        }
    }
    return 0;
}