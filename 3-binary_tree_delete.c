#include <stdlib.h>

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 * Description: If tree is NULL, do nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	/*delete right subtree*/
	binary_tree_delete(tree->right);

	/*delete the left subtree*/
	binary_tree_delete(tree->left);

	/*delete the current node*/
	free(tree);
}
