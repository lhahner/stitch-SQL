/**========================================================================
 * 2025 March 25
 * 
 * Central header file
 *========================================================================**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     STITICHSQL_ASCII    1
#define     STITICHSQL_EBCDIC   2

/**
 * @brief Get the Token object
 * 
 * @param pz 
 * @return int 
 */
unsigned int stitichSQL_getTokenClass(unsigned char **pz, size_t size);

/**
 * @brief Given a token from the string to parse and will 
 * return the number of bytes the token needs also set the
 * token type passed by the second parameter.
 * 
 * @param z the keyword to tokenize 
 * @param tokenClass the tokenclass of the passed keyword
 * @return int the size of the keyword and tokenclass
 */
int stitichSQL_getToken(const unsigned char *z, int* tokenType);