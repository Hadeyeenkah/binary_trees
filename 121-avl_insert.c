#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	/* If tree is empty, create a new node and make it the root */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}

	/* If value is less than the current node's value, go left */
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
	}
	/* If value is greater than the current node's value, go right */
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
	}
	/* If value is already present, return NULL */
	else
	{
		return (NULL);
	}

	/* Update height of this ancestor node */
	(*tree)->height = 1 + max(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));

	/* Get the balance factor to check if this node became unbalanced */
	int balance = binary_tree_balance(*tree);

	/* Left Left Case */
	if (balance > 1 && value < (*tree)->left->n)
		return binary_tree_rotate_right(*tree);

	/* Right Right Case */
	if (balance < -1 && value > (*tree)->right->n)
		return binary_tree_rotate_left(*tree);

	/* Left Right Case */
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return binary_tree_rotate_right(*tree);
	}

	/* Right Left Case */
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return binary_tree_rotate_left(*tree);
	}

	/* Return the unchanged node pointer */
	return (*tree);
}
