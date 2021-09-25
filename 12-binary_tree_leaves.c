#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: leaves of binary tree, or 0 if tree is null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t i, left_i, right_i;

	if (!tree)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_i = binary_tree_leaves(tree->left);
	right_i = binary_tree_leaves(tree->right);
	i = left_i + right_i;
	return (i);
}
