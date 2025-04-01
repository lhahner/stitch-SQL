#include "./includes/test_astree.h"

int test_stitchSQL_pushAstreeNode(void) {
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token* token = malloc(sizeof(Astree_token));
    token->tokenLength = 5;
    token->tokenType = 9;

    stitchSQL_pushAstreeNode(token, &root);

    assert(root != NULL);  // Ensure root is assigned
    assert(root->token.tokenType == 9);  // Validate token assignment

    Astree_token* token1 = malloc(sizeof(Astree_token));
    token1->tokenLength = 5;
    token1->tokenType = 9;

    stitchSQL_pushAstreeNode(token1, &root);

    free(root);
    free(token);
    return 0;
}

int test_stitchSQL_popAstreeNode(void){
    Astree_node *root = NULL;  // Initialize to NULL
    Astree_token *token = malloc(sizeof(Astree_token));
    token->tokenLength = 5;
    token->tokenType = 1;

    Astree_token *token1 = malloc(sizeof(Astree_token));
    token1->tokenLength = 5;
    token1->tokenType = 2;

    Astree_token *token2 = malloc(sizeof(Astree_token));
    token2->tokenLength = 7;
    token2->tokenType = 2;

    Astree_token *token4 = malloc(sizeof(Astree_token));
    token4->tokenLength = 7;
    token4->tokenType = 4;

    Astree_token *token3 = malloc(sizeof(Astree_token));
    token3->tokenLength = 7;
    token3->tokenType = 3;
    //      0
    //  0   0
    stitchSQL_pushAstreeNode(token, &root);
    stitchSQL_pushAstreeNode(token1, &root);
    stitchSQL_pushAstreeNode(token2, &root);
    stitchSQL_pushAstreeNode(token4, &root);
    stitchSQL_pushAstreeNode(token3, &root);
}
