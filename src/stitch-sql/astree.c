/**
 * @file astree.c
 * @author Lennart Hahner (lennart.hahner@gmail.com)
 * @brief Contains code to construct a derived version of an Abstract Syntax Tree.
 * @version 0.1
 * @date 2025-04-08
 * 
 *     (\            Stitch-SQL Copyright (C) 2025 Lennart Hahner
 *    (  \  /(o)\    All Rights Reserved, do not use, distribute 
 *    (   \/  ()/ /) and modify this code.
 *     (   `;.))'".) 
 *      `(/////.-'
 *   =====))=))===() 
 */
#include "includes/astree.h"

Astree_token *stitchSQL_astreetoken_new(int token){
    Astree_token *ptr = malloc(sizeof(Astree_token));
    ptr->tokenType = token;
    if (ptr)
        return ptr;
    else
        return NULL;
}

Astree_node *stitchSQL_astree_new(Astree_token *token)
{
    Astree_node *ptr = malloc(sizeof(Astree_node));
    ptr->token.tokenType = token->tokenType;
    ptr->tokenCount = malloc(sizeof(int));
    *ptr->tokenCount = 1; // Always one if allocated
    if (ptr)
        return ptr;
    else
        return NULL;
}

void stitchSQL_pushAstreeNode(Astree_token *token, Astree_node **parent)
{
    Astree_node *newNode = malloc(sizeof(Astree_node));
    newNode->token = *token;
    newNode->childs = NULL;
    newNode->tokenCount = ((*parent)->tokenCount);
    newNode->childCount = 0;

    // Root
    if (*parent == NULL)
    {
        *parent = newNode;
        return;
    }
    // Lower Hierachy
    else if ((*parent)->token.tokenType < token->tokenType)
    {
        if ((*parent)->childs == NULL || (*parent)->childs->token.tokenType == token->tokenType)
        {
            if (((*parent)->childs != NULL))
            {   
                (*parent)->childCount++;
                (*(*parent)->childs->tokenCount)++;
                (*parent)->childs = realloc((*parent)->childs, sizeof(Astree_node) * (*parent)->childCount);
                (*parent)->childs[(*parent)->childCount-1] = (*newNode);
                return;
            }
            else
            {
                (*parent)->childCount++;
                (*parent)->childs = newNode;
                return;
            }
        }
        else
        {
            stitchSQL_pushAstreeNode(token, &(*parent)->childs);
            return;
        }
    }
    else
    {
        if (((*parent) != NULL))
        {
            (*(*parent)->tokenCount)++;
            *parent = realloc(*parent, sizeof(Astree_node) * (*(*parent)->tokenCount));
            (*parent)[(*(*parent)->tokenCount)-1] = (*newNode);
            
            return;
        }
    }
}

void stitchSQL_popAstreeNode(Astree_node **root)
{
    assert(root != NULL);
    if ((*root)->childs)
    {
        if ((*root)->childs->token.tokenType > (*root)->token.tokenType)
        {
            stitchSQL_popAstreeNode(&(*root)->childs);
            return;
        }
        else
        {
            if ((*root)->childCount > 0)
            {
                (*root)->childCount--;
                (*root)->childs = realloc((*root)->childs, sizeof(Astree_node *) * (*root)->childCount);
            }
            else
            {
                free((*root)->childs);
            }
        }
    }
    else if ((*root)->tokenCount > 0)
    {
        (*(*root)->tokenCount)--;
        Astree_node *tmp_root = malloc(sizeof(Astree_node *));
        memcpy(tmp_root, (*root),  sizeof((*(*root))) * (*(*root)->tokenCount));
        *root = tmp_root;
    }
    else
    {
        free((*root));
    }
}

unsigned int counter = 0;

int stitchSQL_AstreeLength(Astree_node** root){
    if((*root)->childs){
        counter++;
        counter = stitchSQL_AstreeLength(&(*root)->childs);
    }
    else {
        return counter;
    }
    return counter;
}