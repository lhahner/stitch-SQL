/**========================================================================
 * 2025 March 25
 * 
 * Tokenizer for different SQL classes and mapping approaches.
 *========================================================================**/
#include "includes/sitich-sql.h"
#define     AT_KEYW0            1
#define     AT_KEYW             2 /* Alphabetics */
#define     AT_OBRACKET         3 /* ( */
#define     AT_CBRACKET         4 /* ) */
#define     AT_OCBRACKET        5 /* { */
#define     AT_CCBRACKET        6 /* } */
#define     AT_ILLEGAL          7 /* Illegal character */
#define     AT_NUL              8 /* NULL */
#define     AT_SPACE            9 /* Space */
#define     AT_NUM              10 /* Numeric */
#define     APETAIL             11 /* @ */

// Define here the ASCII Code for the different Keywords.
#ifdef STITICHSQL_ASCII
/**
 * @brief 
 * 
 */
const char stitichSQL_ASCII[] = {
/*        x0  x1 x2 x3 x4 x5 x6 x7 x8 x9 xa xb xc xd xe xf */
/* 0x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 1x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 2x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 3x */  11,11,11,11,11,11,11,11,11,11, 9, 9, 9, 9, 9, 9,
/* 4x */  12, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* 5x */   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
/* 6x */   0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* 7x */   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
/* 8x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 9x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ax */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Bx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Cx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Dx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ex */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
};
#elif STITICHSQL_EBCDIC
/**
 * @brief 
 * 
 */
const char stitichSQL_EBCDIC[] = {
/*        x0  x1 x2 x3 x4 x5 x6 x7 x8 x9 xa xb xc xd xe xf */
/* 0x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 1x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 2x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 3x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 4x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 5x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* 6x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 7x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 8x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* 9x */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Ax */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Bx */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Cx */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Dx */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Ex */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Fx */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
/* Fx */   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
#endif

static int getTokenClass(const unsigned char **pz) {
    const unsigned char *z = *pz;
    int t;
    z = z + stitichSQL_getToken(z, &t);
    return t; // Class result for z
}

int stitichSQL_getToken(const unsigned char *z, int* tokenType){
    int i, c;
    switch(stitichSQL_ASCII[*z]){
        case AT_KEYW0: {
            for(i = 0; stitichSQL_ASCII[z[i]]<AT_KEYW; i++){
                if(stitichSQL_ASCII[z[1]]>AT_KEYW) {
                    *tokenType = AT_ILLEGAL;
                    return -1;
                }    
            }
            *tokenType = AT_KEYW;
            return i;
        }
        case AT_OBRACKET: {
            
        }
        case AT_CBRACKET: {

        }
        case AT_OCBRACKET: {

        }
        case AT_CCBRACKET: {

        }
        case AT_ILLEGAL: {

        }
        case AT_NUL: {

        }
        case AT_SPACE: {

        }
        case AT_NUM: {

        }
        case APETAIL: {

        }
        default : {
            *tokenType = AT_ILLEGAL;
            return -1;
        }
    }
    return 0;
}