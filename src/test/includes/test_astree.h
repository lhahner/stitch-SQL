/**
 * @file test_astree.h
 * @author Lennart Hahner (lennart.hahner@gmail.com)
 * @brief This file containes header data for the test code written in test_astree.c
 * @version 0.1
 * @date 2025-04-08
 * 
 * 
 *     (\            Stitch-SQL Copyright (C) 2025 Lennart Hahner
 *    (  \  /(o)\    All Rights Reserved, do not use, distribute 
 *    (   \/  ()/ /) and modify this code.
 *     (   `;.))'".) 
 *      `(/////.-'
 *   =====))=))===() 
 */
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
int test_stitchSQL_pushAStreeNode_caseA(void);

/**
 * @brief Unit test for stitchSQL_popAstreeNode with a specific test case (Case A).
 * 
 * This function tests the behavior of stitchSQL_popAstreeNode in a predefined scenario.
 * It verifies if the function correctly removes a node.
 * 
 * @return int Returns 0 if the test passes, non-zero if it fails.
 */
int test_stitchSQL_popAstreeNode_caseA(void);

/**
 * @brief Unit test for stitchSQL_popAstreeNode_caseB with a specific test case (Case A).
 * 
 * This function tests the behavior of stitchSQL_popAstreeNode_caseB in a predefined scenario.
 * It verifies if the function correctly removes a node.
 * 
 * @return int Returns 0 if the test passes, non-zero if it fails.
 */
int test_stitchSQL_popAstreeNode_caseB(void);

/**
 * @brief Unit test for stitchSQL_AstreeLength with a specific test case.
 * 
 * This function verifies if the correct length of the Astree is returned.
 * 
 * @return int Returns 0 of the test passes, non-zero of it fails. 
 */
int test_stitchSQL_AstreeLength(void);

/**
 * @brief Unit test forstitchSQL_pushAstreeNode with a specific test case (Case C).
 * 
 * This function 
 * 
 * @return int 
 */
int test_stitchSQL_pushAstreeNode_caseC(void);