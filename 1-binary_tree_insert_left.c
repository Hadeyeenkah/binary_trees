#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *My_newNode;

	if (!parent)
		return (NULL);

	My_newNode = binary_tree_node(parent, value);
	if (!My_newNode)
		return (NULL);

	if (parent->left)
	{
		My_newNode->left = parent->left;
		parent->left->parent = My_newNode;
		parent->left = My_newNode;
	}
	else
		parent->left = My_newNode;
	return (My_newNode);
}
