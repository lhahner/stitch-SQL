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

int test_stitchSQL_pushAstreeNode(void)
{   
    // Construction a ideal test AST for just one expression
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);
    
    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token token3 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token3, &ast);

    Astree_token token5 = stitchSQL_astreetoken_new(5);
    stitchSQL_pushAstreeNode(token5, &ast);
    int c = ast->childs[0]->token.tokenType;

    assert(c == 2);
    return 0;
}

int test_stitchSQL_pushAStreeNode_caseA(void)
{
    // Construction a ideal test AST for just one expression
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);
    
    assert(ast->token.tokenType == 1);

    Astree_token token1 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token1, &ast);

    assert(ast[1].token.tokenType == 1);

    Astree_token token2 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token2, &ast);

    assert(ast[2].token.tokenType == 1);
    return 0;
}

int test_stitchSQL_pushAstreeNode_caseB(void)
{
    // Construction a ideal test AST for just one expression
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);
    
    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token token3 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token3, &ast);

    Astree_token token4 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token4, &ast);

    
    assert(ast->token.tokenType == 1);
    assert(ast->childs[0]->token.tokenType == 2);
    assert(ast->childs[0]->childs[0]->token.tokenType == 3);
    assert(ast->childs[0]->childs[1]->token.tokenType == 3);
    return 0;
}

int test_stitchSQL_pushAstreeNode_caseC(void)
{
    // Construction a ideal test AST for just one expression
    Astree_token token = stitchSQL_astreetoken_new(0);
    Astree_node *ast = stitchSQL_astree_new(token);

    Astree_token token1 = stitchSQL_astreetoken_new(1);
    stitchSQL_pushAstreeNode(token1, &ast);
    
    Astree_token token2 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token2, &ast->childs);

    Astree_token token3 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token3, &ast);
    
    assert(ast->token.tokenType == 0);
    assert(ast->childs[0]->childs[0]->token.tokenType == 2);
    assert(ast->childs[0]->childs[0]->childs[0]->token.tokenType == 3);

    return 0;
}

int test_stitchSQL_popAstreeNode(void)
{
    // TODO
    return 0;
}

int test_stitchSQL_popAstreeNode_caseA(void)
{
    // TODO
    return 0;
}

int test_stitchSQL_popAstreeNode_caseB(void)
{
    // Construction of test AST
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);
    
    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token token2 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token token3 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token3, &ast);

    Astree_token token4 = stitchSQL_astreetoken_new(5);
    stitchSQL_pushAstreeNode(token4, &ast);

    stitchSQL_popAstreeNode(&ast);

    free(ast);
    return 0;
}

int test_stitchSQL_astreetoken_new(void)
{
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);
    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);
    assert(ast != NULL);

    free(ast);
    return 0;
}

int test_stitchSQL_AstreeLength(void)
{
    // Construction of test AST
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);

    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token token2 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token token3 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token3, &ast);

    int c = stitchSQL_AstreeLength(&ast);
    assert(c == 3);
    free(ast);
    return 0;
}

int test_stitichSQL_tokenCount(void)
{
    // Construction of test AST
    Astree_token token = stitchSQL_astreetoken_new(1);
    Astree_node *ast = stitchSQL_astree_new(token);

    Astree_token token1 = stitchSQL_astreetoken_new(2);
    stitchSQL_pushAstreeNode(token1, &ast);

    Astree_token token2 = stitchSQL_astreetoken_new(3);
    stitchSQL_pushAstreeNode(token2, &ast);

    Astree_token token5 = stitchSQL_astreetoken_new(4);
    stitchSQL_pushAstreeNode(token5, &ast);

    Astree_token token6 = stitchSQL_astreetoken_new(5);
    stitchSQL_pushAstreeNode(token6, &ast);

    // TODO
    return 0;
}