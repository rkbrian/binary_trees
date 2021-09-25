B#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: node count, or 0 if tree is null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t i, left_i, right_i;

	if (!tree)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_i = binary_tree_nodes(tree->left);
	right_i = binary_tree_nodes(tree->right);
	i = left_i + right_i;
	return (i + 1);
}
