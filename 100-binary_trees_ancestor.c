#include "binary_trees.h"

/**
 * find_ancestor - Recursively find the lowest common ancestor
 * @root: Pointer to the current root node
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor found
 */
binary_tree_t *find_ancestor(const binary_tree_t *root,
		const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (root == NULL)
		return NULL;

	if (root == first || root == second)
		return (binary_tree_t *)root;

	left = find_ancestor(root->left, first, second);
	right = find_ancestor(root->right, first, second);

	if (left && right)
		return (binary_tree_t *)root;

	return left ? left : right;
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if no common ancestor found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return NULL;

	return find_ancestor(first, first, second);
}
