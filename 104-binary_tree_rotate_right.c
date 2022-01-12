#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the new root node, or null
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *new_root = NULL, *parent = NULL;

	if (!tree || !tree->left)
		return (NULL);
	tmp = tree, new_root = tree->left, parent = tmp->parent;
	tmp->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tmp;
	tmp->parent = new_root;
	new_root->right = tmp;
	new_root->parent = parent;
	if (parent && parent->left && parent->left->n == tmp->n)
		parent->left = new_root;
	else if (parent && parent->right && parent->right->n == tmp->n)
		parent->right = new_root;
	return (new_root);
}
