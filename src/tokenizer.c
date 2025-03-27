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
#define     AT_MINUS            7 /* } */
#define     AT_ILLEGAL          8 /* Illegal character */
#define     AT_NUL              9 /* NULL */
#define     AT_SPACE            10 /* Space */
#define     AT_NUM              11 /* Numeric */
#define     AT_ID               12 /* Identfier */
#define     AT_COMMENT          13 /* Comments */

// Define here the ASCII Code for the different Keywords.
#ifdef STITICHSQL_ASCII

const char stitichSQL_ASCII[] = {
/*        x0  x1 x2 x3 x4 x5 x6 x7 x8 x9 xa xb xc xd xe xf */
/* 0x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 1x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 2x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 7, 9, 9,
/* 3x */   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9,
/* 4x */   1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
/* 5x */   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8, 8, 8, 8,
/* 6x */   8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
/* 7x */   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 8, 8, 8, 8,
/* 8x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* 9x */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ax */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9,
/* Bx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Cx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Dx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Ex */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
/* Fx */   9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9
};
#elif STITICHSQL_EBCDIC

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

unsigned int stitichSQL_getTokenClass(unsigned char **pz, size_t size) {
    unsigned char* z = *pz;
    int t;
    for(int i = 0; i<size/sizeof(char*); i++){
        stitichSQL_getToken(z, &t); 
        pz++;
        z = *pz;
    }
    return t; // Class result for z
}

int stitichSQL_getToken(const unsigned char *z, int* tokenType){
    int i = 0, c;
    switch(stitichSQL_ASCII[*z]){
        case AT_MINUS: {
            if(z[1]=='-'){
                for(i=2; c!=0&&c!='\n';i++){
                    c = z[i];
                }
                *tokenType = AT_COMMENT;
                return i;
            }
            else {
                *tokenType = AT_NUL;
            }
        }
        case AT_KEYW0: {
            for(; stitichSQL_ASCII[z[i]]<AT_OBRACKET; i++){
                if(stitichSQL_ASCII[z[1]]>AT_KEYW) {
                    *tokenType = AT_ILLEGAL;
                    return -1;
                }    
            }
            *tokenType = AT_KEYW;
            return i;
        }
        case AT_OBRACKET: {
            *tokenType = AT_OBRACKET;
            i++;
            return i;
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