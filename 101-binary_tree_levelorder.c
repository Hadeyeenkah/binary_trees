#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: Function that goes through a binary tree using level-order
 * traversal, also known as breadth-first traversal. It visits nodes level by
 * level, from left to right.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	int front = 0, rear = 0;
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* Call func for the current node */
		func(current->n);

		/* Enqueue left child */
		if (current->left)
			queue[rear++] = current->left;

		/* Enqueue right child */
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}
