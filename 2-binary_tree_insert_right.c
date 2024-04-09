#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 *					right-child of another node
 *
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Description: If parent already has a right-child, the new node
 *				must take its place, and the old right-child must
 *				be set as the right-child of the new node.
 *
 * Return: a pointer to the created node, or
 *			NULL on failure or
 *			if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *My_newNode;

	if (!parent)
		return (NULL);

	My_newNode = binary_tree_node(parent, value);
	if (!My_newNode)
		return (NULL);
	if (parent->right)
	{
		My_newNode->right = parent->right;
		parent->right->parent = My_newNode;
		parent->right = My_newNode;
	}
	else
		parent->right = My_newNode;
	return (My_newNode);
}
