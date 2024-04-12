#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	size_t count = binary_tree_size(tree);
	return is_complete(tree, 0, count);
}

/**
 * is_complete - Helper function to recursively check if a binary tree is complete
 * @tree: A pointer to the current node in the binary tree
 * @index: The index of the current node in a complete binary tree
 * @count: The total number of nodes in the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t count)
{
	if (tree == NULL)
		return 1;

	if (index >= count)
		return 0;

	return (is_complete(tree->left, 2 * index + 1, count) &&
			is_complete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure the size of
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

