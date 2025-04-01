/**========================================================================
 * 2025 March 31
 * 
 * Abstract Syntax tree for storing all the tokens that the tokenizer
 * will provide and that are replaced by different strings.
 *========================================================================**/
#include "includes/astree.h"

void stitchSQL_pushAstreeNode(Astree_token* token, Astree_node** parent) {
    Astree_node *newNode = malloc(sizeof(Astree_node));
    newNode->token = *token;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*parent == NULL) {
        *parent = newNode;  // Assign newNode to root
        return;
    } else if ((*parent)->left == NULL) {
        (*parent)->left = newNode;
        return;
    } else if((*parent)->right == NULL) {
        (*parent)->right = newNode;
        return;
    } else {
        stitchSQL_pushAstreeNode(token, &(*parent)->left);
    }
    return;
}

void stitchSQL_popAstreeNode(Astree_node** root) {
    //TODO
}