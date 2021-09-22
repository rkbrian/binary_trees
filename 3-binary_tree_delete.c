#include "binary_trees.h"

/**
 * binary_tree_delete - function that deletes an entire binary tree
 * @tree: to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree) /* depth-first search */
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree); /* post-order traversal */
	}
}
