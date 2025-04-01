/**========================================================================
 * 2025 March 31
 * 
 * Abstract Syntax tree for storing all the tokens that the tokenizer
 * will provide and that are replaced by different strings.
 *========================================================================**/
#include "includes/astree.h"

Astree_node *ast_new(Astree_node ast) {
  Astree_node *ptr = malloc(sizeof(Astree_node));
  if (ptr) *ptr = ast;
  return ptr;
}  

void stitchSQL_pushAstreeNode(Astree_token* token, Astree_node** parent) {
    Astree_node *newNode = malloc(sizeof(Astree_node));
    newNode->token = *token;
    newNode->childs = NULL;
    newNode->childCount = 0;

    // Root
    if (*parent == NULL) {
        *parent = newNode;
        return;
    } 
    // Lower Hierachy
    else if((*parent)->token.tokenType < token->tokenType){
        if((*parent)->childs == NULL || (*parent)->childs->token.tokenType == token->tokenType){
            if(((*parent)->childs != NULL)){
                (*parent)->childCount++;
                (*parent)->childs = realloc((*parent)->childs, sizeof(Astree_node) * (*parent)->childCount);
                (*parent)->childs[(*parent)->childCount] = (*newNode);
                return;
            }
            else {
                (*parent)->childs = newNode;
                return;
            }
        } 
        else {
            stitchSQL_pushAstreeNode(token, &(*parent)->childs);
            return;
        }
    } else {
        if(((*parent) != NULL)){
            (*parent)->childCount++;
            *parent = realloc(*parent, sizeof(Astree_node) * (*parent)->childCount);
            (*parent)[(*parent)->childCount] = (*newNode);
            return;
        }
    }
}