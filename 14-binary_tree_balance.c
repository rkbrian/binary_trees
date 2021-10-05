#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: balance factor of binary tree, or 0 if tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_tr, right_tr;

	if (!tree)
		return (0);
	if (!tree->left)
		left_tr = 0;
	else
		left_tr = binary_tree_height(tree->left) + 1;
	if (!tree->right)
		right_tr = 0;
	else
		right_tr = binary_tree_height(tree->right) + 1;
	return (left_tr - right_tr);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of binary tree, or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i, lefti, righti;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);
	lefti = binary_tree_height(tree->left);
	righti = binary_tree_height(tree->right);
	if (lefti >= righti)
		i = lefti;
	else
		i = righti;
	return (i + 1);
}
