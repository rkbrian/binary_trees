#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: size of binary tree, or 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t i = 0, left_i, right_i;

	if (!tree)
		return(0);
	else if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_i = binary_tree_size(tree->left);
	right_i = binary_tree_size(tree->right);
	i = left_i + right_i;
	return (i + 1);
}
