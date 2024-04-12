#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (height_left > height_right ? height_left + 1 : height_right + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (1);

	if (!binary_tree_is_bst(tree))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (abs(height_left - height_right) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

