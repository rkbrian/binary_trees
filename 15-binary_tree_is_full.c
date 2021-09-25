#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: pointer to the root node of the tree to traverse
 * Return: 1 if tree is full, or 0 if not full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int halves;

	if (!tree)
		return (0);
	halves = binary_tree_halfbranch(tree);
	if (halves > 0)
		return (0);
	return (1);
}

/**
 * binary_tree_halfbranch - counts the nodes with only 1 child in a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: node count, or 0 if tree is null
 */
size_t binary_tree_halfbranch(const binary_tree_t *tree)
{
	size_t i, left_i, right_i;

	if (!tree)
		return (0);
	else if (tree->left == NULL && tree->right == NULL)
		return (0);
	left_i = binary_tree_halfbranch(tree->left);
	right_i = binary_tree_halfbranch(tree->right);
	i = left_i + right_i;
	if (tree->left && tree->right)
		return (i);
	return (i + 1);
}
