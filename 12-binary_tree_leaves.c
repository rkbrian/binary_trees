#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: leaves of binary tree, or 0 if tree is null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t i = 0;

	if (!tree)
		return(0);
	if (tree && tree->left)
		i++;
	if (tree && tree->right)
		i++;
	return (i);
}
