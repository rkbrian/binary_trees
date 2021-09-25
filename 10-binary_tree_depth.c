#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: depth of binary tree, or 0 if tree is null
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;

	if (tree)
	{
		while (tree->parent)
			tree = tree->parent, i++;
		return (i);
	}
	return (0);
}
