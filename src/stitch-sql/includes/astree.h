#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
 * @brief 
 * 
 */
typedef struct Astree_token {
        int tokenType;
        int tokenLength;
} Astree_token;

/**
 * @brief 
 * 
 */
typedef struct Astree_node {
    Astree_token token;
    // etc ...
    struct Astree_node *childs;
    int childCount; // Number of children
} Astree_node;

/**
 * @brief 
 * 
 * @param ast 
 * @return Astree_node* 
 */
Astree_node *ast_new(Astree_node ast);

/**
 * @brief 
 * 
 * @return int 
 */
void stitchSQL_pushAstreeNode(Astree_token* token, Astree_node** parent);

/**
 * @brief 
 * 
 * @return int 
 */
void stitchSQL_popAstreeNode(Astree_node** root);