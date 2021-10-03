#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the new root node, or null
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *new_root = NULL;

	if (!tree || !tree->left)
		return (NULL);
	tmp = tree, new_root = tree->left;
	tmp->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tmp;
	tmp->parent = new_root;
	new_root->right = tmp;
	new_root->parent = NULL;
	return (new_root);
}
