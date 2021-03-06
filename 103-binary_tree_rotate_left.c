#include "binary_trees.h"

/**
 * binary_tree_rotate_left - perform a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the new root node, or null
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *new_root = NULL, *parent = NULL;

	if (!tree || !tree->right)
		return (NULL);
	tmp = tree, new_root = tree->right, parent = tmp->parent;
	tmp->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tmp;
	tmp->parent = new_root;
	new_root->left = tmp;
	new_root->parent = parent;
	if (parent && parent->left && parent->left->n == tmp->n)
		parent->left = new_root;
	else if (parent && parent->right && parent->right->n == tmp->n)
		parent->right = new_root;
	return (new_root);
}
