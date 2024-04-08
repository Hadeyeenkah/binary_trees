#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/*declaration of the new node with the data type*/
	binary_tree_t *My_newNode;

	/*allocate memory space for the node*/
	My_newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (My_newNode == NULL)
	{
		return (NULL);
	}
	/*assign values to the properties of the node*/
	My_newNode->n = value;
	My_newNode->parent = parent;
	My_newNode->left = NULL;
	My_newNode->right = NULL;

	return (My_newNode);
}
