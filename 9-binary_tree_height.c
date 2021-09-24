#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of binary tree, or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0, lefti, righti;

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
