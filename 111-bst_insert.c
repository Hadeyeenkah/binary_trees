#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = NULL;
	new_node = *tree;

	while (new_node != NULL)
	{
		parent = new_node;
		if (value == new_node->n)
			return (NULL);
		else if (value < new_node->n)
			new_node = new_node->left;
		else
			new_node = new_node->right;
	}

	if (value < parent->n)
		parent->left = binary_tree_node(parent, value);
	else
		parent->right = binary_tree_node(parent, value);

	return (parent);
}

