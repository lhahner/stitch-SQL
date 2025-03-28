#include "stitch-sql.h"
#define     STITCHSQL_ASCII    1
#define     STITCHSQL_EBCDIC   2

/**
 * @brief Get the Token object
 * 
 * @param pz 
 * @return int 
 */
unsigned int stitchSQL_getTokenClass(unsigned char **pz, size_t size);

/**
 * @brief Given a token from the string to parse and will 
 * return the number of bytes the token needs also set the
 * token type passed by the second parameter.
 * 
 * @param z the keyword to tokenize 
 * @param tokenClass the tokenclass of the passed keyword
 * @return int the size of the keyword and tokenclass
 */
int stitchSQL_getToken(const unsigned char *z, int* tokenType);