#include "../../stitch-sql/includes/astree.h"

/**
 * @brief Tests the functionality of pushing a node onto the AST (Abstract Syntax Tree) stack.
 * 
 * This function verifies whether the push operation correctly adds a new node to the AST stack
 * and maintains the expected tree structure.
 * 
 * @return int Returns 0 on success, or a nonzero value if the test fails.
 */
int test_stitchSQL_pushAstreeNode(void);

/**
 * @brief Tests the functionality of popping a node from the AST stack.
 * 
 * This function ensures that the pop operation correctly removes a node from the AST stack
 * and maintains tree integrity after removal.
 * 
 * @return int Returns 0 on success, or a nonzero value if the test fails.
 */
int test_stitchSQL_popAstreeNode(void);

/**
 * @brief Unit test for stitchSQL_astreetoken_new function.
 * 
 * This function tests the creation of a new AST token using stitchSQL_astreetoken_new.
 * It checks whether the function correctly allocates and initializes a token.
 * 
 * @return int Returns 0 if the test passes, non-zero if it fails.
 */
int test_stitchSQL_astreetoken_new(void);

/**
 * @brief Unit test for stitchSQL_pushAstreeNode with a specific test case (Case A).
 * 
 * This function tests the behavior of stitchSQL_pushAstreeNode in a predefined scenario.
 * It verifies if the function correctly adds a child node to a parent node.
 * 
 * @return int Returns 0 if the test passes, non-zero if it fails.
 */
int test_stitchSQL_pushAstreeNode_caseA(void);