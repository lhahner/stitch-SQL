/**
 * @file test_astree.c
 * @author Lennart Hahner (lennart.hahner@gmail.com)
 * @brief This file includes code to test the Abstract Syntax Tree that contains
 * the tokens extracted from the tokenizer out of the SQL code.
 * @version 0.1
 * @date 2025-04-08
 * 
 *     (\            Stitch-SQL Copyright (C) 2025 Lennart Hahner
 *    (  \  /(o)\    All Rights Reserved, do not use, distribute 
 *    (   \/  ()/ /) and modify this code.
 *     (   `;.))'".) 
 *      `(/////.-'
 *   =====))=))===() 
 **/
#include "./includes/test_astree.h"

int test_stitchSQL_pushAstreeNode(void) {
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token *token = malloc(sizeof(Astree_token));
    token->tokenType = 1; // Worksheet

    Astree_token *token1 = malloc(sizeof(Astree_token));
    token1->tokenType = 2; // Table

    Astree_token *token2 = malloc(sizeof(Astree_token));
    token2->tokenType = 2; // Table

    Astree_token *token4 = malloc(sizeof(Astree_token));
    token4->tokenType = 4; // Row

    Astree_token *token3 = malloc(sizeof(Astree_token));
    token3->tokenType = 3; // Cell

    stitchSQL_pushAstreeNode(token, &root);
    stitchSQL_pushAstreeNode(token1, &root);
    stitchSQL_pushAstreeNode(token2, &root);
    stitchSQL_pushAstreeNode(token4, &root);
    stitchSQL_pushAstreeNode(token3, &root);
    return 0;
}

int test_stitchSQL_popAstreeNode(void){
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token *token = malloc(sizeof(Astree_token));
    token->tokenType = 1; // Worksheet

    Astree_token *token1 = malloc(sizeof(Astree_token));
    token1->tokenType = 2; // Table

    Astree_token *token2 = malloc(sizeof(Astree_token));
    token2->tokenType = 2; // Table

    Astree_token *token4 = malloc(sizeof(Astree_token));
    token4->tokenType = 4; // Row

    Astree_token *token3 = malloc(sizeof(Astree_token));
    token3->tokenType = 3; // Cell

    stitchSQL_pushAstreeNode(token, &root);
    stitchSQL_pushAstreeNode(token1, &root);
    stitchSQL_pushAstreeNode(token2, &root);
    stitchSQL_pushAstreeNode(token4, &root);
    stitchSQL_pushAstreeNode(token3, &root);

    stitchSQL_popAstreeNode(&root);

    assert(&root->childs->childs[1] != 3);
    return 0;
}

int test_stitchSQL_astreetoken_new(void){
    Astree_token* token = stitchSQL_astreetoken_new(0);
    Astree_node* ast = stitchSQL_astree_new(token);
    Astree_token* token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);
    assert(ast != NULL);
    return 0;
}

int test_stitchSQL_pushAStreeNode_caseA(void){
    Astree_token* token = stitchSQL_astreetoken_new(9);
    Astree_node* ast = stitchSQL_astree_new(token);

    Astree_token* token1 = stitchSQL_astreetoken_new(8);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token* token2 = stitchSQL_astreetoken_new(7);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token* token3 = stitchSQL_astreetoken_new(7);
    stitchSQL_pushAstreeNode(token3, &ast);
    
    assert(ast->childs == NULL);
    return 0;
}

int test_stitchSQL_popAstreeNode_caseA(void){
    // Construction of test AST
    Astree_token* token = stitchSQL_astreetoken_new(9);
    Astree_node* ast = stitchSQL_astree_new(token);

    Astree_token* token1 = stitchSQL_astreetoken_new(8);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token* token2 = stitchSQL_astreetoken_new(7);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token* token3 = stitchSQL_astreetoken_new(9);
    stitchSQL_pushAstreeNode(token3, &ast);

    stitchSQL_popAstreeNode(&ast);
    
    assert(*(ast->tokenCount) == 3);

    return 0;
}

int test_stitchSQL_popAstreeNode_caseB(void){
    // Construction of test AST
    Astree_token* token = stitchSQL_astreetoken_new(0);
    Astree_node* ast = stitchSQL_astree_new(token);

    Astree_token* token1 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token* token2 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token* token3 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token3, &ast);

    Astree_token* token4 = stitchSQL_astreetoken_new(4);
    stitchSQL_pushAstreeNode(token4, &ast);

    stitchSQL_popAstreeNode(&ast);
    
    assert(*(ast->childs->tokenCount) == 2);
    return 0;
}

int test_stitchSQL_AstreeLength(void){
     // Construction of test AST
    Astree_token* token = stitchSQL_astreetoken_new(0);
    Astree_node* ast = stitchSQL_astree_new(token);

    Astree_token* token1 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token* token2 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token* token3 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token3, &ast);

    Astree_token* token4 = stitchSQL_astreetoken_new(4);
    stitchSQL_pushAstreeNode(token4, &ast);

    int c = stitchSQL_AstreeLength(&ast);
    assert(c == 3);
    return 0;
}