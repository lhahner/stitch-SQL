#include "../../stitch-sql/includes/tokenizer.h"

/**
 * @brief Tests the stitchSQL_getToken function for recognizing curly brackets.
 * 
 * This function checks if the tokenizer correctly identifies curly brackets `{}` 
 * and assigns them the appropriate token class.
 * 
 * @return int Returns 0 if successful, -1 if not.
 */
int test_stitchSQL_getToken_curly_bracket(void);

/**
 * @brief Tests the stitchSQL_getToken function for recognizing SQL keywords.
 * 
 * This function verifies if the tokenizer correctly identifies SQL keywords 
 * (e.g., SELECT, INSERT, WHERE) and classifies them properly.
 * 
 * @return int Returns 0 if successful, -1 if not.
 */
int test_stitchSQL_getToken_keyword(void);

/**
 * @brief Tests the stitchSQL_getTokenClass function.
 * 
 * This function ensures that the token classification mechanism properly 
 * assigns the correct token type to various input strings.
 * 
 * @return int Returns 0 if successful, -1 if not.
 */
int test_stitchSQL_getTokenClass(void);

/**
 * @brief Tests the stitchSQL_getToken function for recognizing comments.
 * 
 * This function checks whether the tokenizer correctly identifies single-line (`--`) 
 * comments.
 * 
 * @return int Returns 0 if successful, -1 if not.
 */
int test_stitchSQL_getToken_comment(void);

/**
 * @brief Tests the stitchSQL_getToken function for recognizing brackets.
 * 
 * This function verifies if the tokenizer correctly identifies different types of brackets 
 * such as `()`, `[]`, and assigns them the correct token classification.
 * 
 * @return int Returns 0 if successful, -1 if not.
 */
int test_stitchSQL_getToken_bracket(void);