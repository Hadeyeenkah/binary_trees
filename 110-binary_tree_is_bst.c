#include "binary_trees.h"

/**
 * is_bst_util - Helper function to recursively check if a binary tree is a valid BST
 * @tree: A pointer to the current node in the binary tree
 * @min: The minimum value allowed for this node
 * @max: The maximum value allowed for this node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return is_bst_util(tree, INT_MIN, INT_MAX);
}

/**
 * is_bst_util - Helper function to recursively check if a binary tree is a valid BST
 * @tree: A pointer to the current node in the binary tree
 * @min: The minimum value allowed for this node
 * @max: The maximum value allowed for this node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return 1;

	if (tree->n < min || tree->n > max)
		return 0;

	return is_bst_util(tree->left, min, tree->n - 1) &&
		is_bst_util(tree->right, tree->n + 1, max);
}
