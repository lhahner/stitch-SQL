#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * @brief Represents a token in the abstract syntax tree (AST).
 * This structure holds information about a token such as its type and length.
 */
typedef struct Astree_token {
        int tokenType;    /**< Type of the token (e.g., keyword, operator, identifier, etc.) */
} Astree_token;

/**
 * @brief Represents a node in the abstract syntax tree (AST).
 * This structure represents a node in the AST that holds a token and pointers to its child nodes.
 */
typedef struct Astree_node {
    Astree_token token;  /**< Token associated with this node */
    // Add any additional fields here (e.g., parent pointer, sibling pointer, etc.)
    struct Astree_node *childs;  /**< Pointer to the list of child nodes */
    int childCount;   /**< Number of children of this node */
} Astree_node;

/**
 * @brief Pushes a new AST node onto the current tree structure.
 * This function adds a new child node to the given parent node in the AST.
 * 
 * @param token The token to be added as a child node.
 * @param parent The parent node to which the new node will be added.
 */
void stitchSQL_pushAstreeNode(Astree_token* token, Astree_node** parent);

/**
 * @brief Pops the last AST node from the current tree structure.
 * This function removes the most recently added node from the AST, effectively backtracking in the tree structure.
 * 
 * @param root The root of the tree, from which the last node will be removed.
 */
void stitchSQL_popAstreeNode(Astree_node** root);

/**
 * @brief Creates a new AST node with a given token.
 * This function creates a new node and assigns the provided token to it.
 * 
 * @param token The token to assign to the new node.
 * @return A pointer to the newly created node.
 */
Astree_node *stitchSQL_astree_new(Astree_token *token);

/**
 * @brief Allocates and initializes a new AST token.
 * 
 * This function creates a new token and assigns the given token type to it.
 * It returns a pointer to the newly allocated token.
 * 
 * @param token The integer value representing the type of the token.
 * @return Astree_token* Pointer to the newly created token, or NULL on failure.
 */
Astree_token *stitchSQL_astreetoken_new(int token);