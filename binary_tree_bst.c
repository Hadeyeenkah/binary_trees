#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->left->n >= tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n <= tree->n)
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
