#include "./includes/test_astree.h"

int test_stitchSQL_pushAstreeNode(void) {
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token *token = malloc(sizeof(Astree_token));
    token->tokenLength = 5;
    token->tokenType = 1; // Worksheet

    Astree_token *token1 = malloc(sizeof(Astree_token));
    token1->tokenLength = 5;
    token1->tokenType = 2; // Table

    Astree_token *token2 = malloc(sizeof(Astree_token));
    token2->tokenLength = 7;
    token2->tokenType = 2; // Table

    Astree_token *token4 = malloc(sizeof(Astree_token));
    token4->tokenLength = 7;
    token4->tokenType = 4; // Row

    Astree_token *token3 = malloc(sizeof(Astree_token));
    token3->tokenLength = 7;
    token3->tokenType = 3; // Cell

    stitchSQL_pushAstreeNode(token, &root);
    stitchSQL_pushAstreeNode(token1, &root);
    stitchSQL_pushAstreeNode(token2, &root);
    stitchSQL_pushAstreeNode(token4, &root);
    stitchSQL_pushAstreeNode(token3, &root);
    return 0;
}

int test_stitchSQL_popAstreeNode(){
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token *token = malloc(sizeof(Astree_token));
    token->tokenLength = 5;
    token->tokenType = 1; // Worksheet

    Astree_token *token1 = malloc(sizeof(Astree_token));
    token1->tokenLength = 5;
    token1->tokenType = 2; // Table

    Astree_token *token2 = malloc(sizeof(Astree_token));
    token2->tokenLength = 7;
    token2->tokenType = 2; // Table

    Astree_token *token4 = malloc(sizeof(Astree_token));
    token4->tokenLength = 7;
    token4->tokenType = 4; // Row

    Astree_token *token3 = malloc(sizeof(Astree_token));
    token3->tokenLength = 7;
    token3->tokenType = 3; // Cell

    stitchSQL_pushAstreeNode(token, &root);
    stitchSQL_pushAstreeNode(token1, &root);
    stitchSQL_pushAstreeNode(token2, &root);
    stitchSQL_pushAstreeNode(token4, &root);
    stitchSQL_pushAstreeNode(token3, &root);

    stitchSQL_popAstreeNode(&root);

    assert(&root->childs->childs[1] != 3);
}