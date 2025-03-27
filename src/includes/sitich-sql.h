/**========================================================================
 * 2025 March 25
 * 
 * Central header file
 *========================================================================**/
#include <stdio.h>
#include <stdlib.h>
#define     STITICHSQL_ASCII    1
#define     STITICHSQL_EBCDIC   2


/**
 * @brief Get the Token object
 * 
 * @param pz 
 * @return int 
 */
static int getTokenClass(const unsigned char **pz);

/**
 * @brief Running test for the getTokenClass
 * 
 * @return int 
 */
int test_getTokenClass();

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

/**
 * @brief tests the stitichSQL_getToken function with a basic string
 * and if it is identfied with the correct class.
 * 
 * @return int 0 if sucessful and -1 if not
 */
int test_stitichSQL_getToken_bracket();

/**
 * @brief tests the stitichSQL_getToken function with a basic string
 * and if it is identfied with the correct class.
 * 
 * @return int 0 if sucessful and -1 if not
 */
int test_stitichSQL_getToken_keyword();