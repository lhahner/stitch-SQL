/**
 * @file astree.c
 * @author Lennart Hahner (lennart.hahner@gmail.com)
 * @brief Contains code to construct a derived version of an Abstract Syntax Tree (AST).
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
/**
 * @brief A global counter to count the depth of childs in the ASTree.
 */
unsigned int counter = 0;

Astree_token stitchSQL_astreetoken_new(int token)
{
    Astree_token tk;
    tk.tokenType = token;
    return tk;
}

Astree_node *stitchSQL_astree_new(Astree_token token)
{
    Astree_node *ptr;
    if((ptr = ( Astree_node*)malloc(sizeof(Astree_node*))) != NULL){
        ptr->token.tokenType = token.tokenType;
        ptr->childCount = 0;
    if (ptr)
    {
        return ptr;
    }
    else
        return NULL;
    }
    else {
        perror("Malloc error");
        abort();
    }
}

void stitchSQL_pushAstreeNode(Astree_token token, Astree_node **parent)
{
    // Root
    if (*parent == NULL)
    {
        *parent = stitchSQL_astree_new(token);
        return;
    }
    // Lower Hierachy
    else if ((*parent)->token.tokenType < token.tokenType)
    {
        if ((*(*parent)->childs) == NULL || (*(*parent)->childs)->token.tokenType == token.tokenType)
        {
            if (((*(*parent)->childs) != NULL))
            {
                (*parent) = stitichSQL_enlargeNodeMem(((*parent)), token.tokenType);
                return;
            }
            else
            {
                (*parent)->childs[0] = (Astree_node*)stitchSQL_astree_new(token);
                return;
            }
        }
        else
        {
            stitchSQL_pushAstreeNode(token, &(*parent)->childs[0]);
            return;
        }
    }
    else
    {
        if (((*parent) != NULL))
        {
            *parent = stitichSQL_enlargeNodeMem(*parent, token.tokenType);
            return;
        }
    }
}

void stitchSQL_popAstreeNode(Astree_node **root)
{
    unsigned int tokenCount = stitichSQL_tokenCount(*root);
    assert(root != NULL);
    if ((*root)->childs)
    {
        if ((*(*root)->childs)->token.tokenType > (*root)->token.tokenType)
        {
            stitchSQL_popAstreeNode(&(*root)->childs);
            return;
        }
        else
        {
            if ((*root)->childCount > 0)
            {
                (*root)->childCount--;
                (*(*root)->childs) = realloc((*root)->childs, sizeof(Astree_node *) * (*root)->childCount);
            }
            else
            {
                free((*root)->childs);
            }
        }
    }
    else if (tokenCount > 0)
    {
        tokenCount--;
        Astree_node *tmp_root = malloc(sizeof(Astree_node *));
        memcpy(tmp_root, (*root), sizeof((*(*root))) * tokenCount);
        *root = tmp_root;
    }
    else
    {
        free((*root));
    }
}

int stitchSQL_AstreeLength(Astree_node **root)
{
    if ((*root)->childs)
    {
        counter++;
        counter = stitchSQL_AstreeLength(&(*root)->childs);
    }
    else
    {
        return counter;
    }
    return counter;
}

int stitichSQL_tokenCount(Astree_node *node)
{
    unsigned int c;
    if (node)
    {
        for (c = 0;; c++)
        {
            assert(node);
            if (node[c].token.tokenType)
            {
            }
            else
                return c;
        }
    }
    else
        return -1;
}

Astree_node *stitichSQL_enlargeNodeMem(Astree_node *node, int token)
{
    Astree_node* nodeTmp;
    node->token.tokenType = token;
    if((nodeTmp = (Astree_node*)malloc(sizeof(Astree_node*))) != NULL){
        int i = 0;
        while(node->childs[i]){
            i++;
        }
        node->childs[i] = nodeTmp;
        return node;
    }
    else {
        perror( "Out of storage" );
        abort();
    }
    return NULL;
}

int stitichSQL_reduceNodeMem()
{
    // TODO makes the Node Pointer smaller when removeing one node.
    return 0;
}