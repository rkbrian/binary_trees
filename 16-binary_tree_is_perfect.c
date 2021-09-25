#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to traverse
 * Return: 1 if tree is perfect, or 0 if not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, node_sum;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	node_sum = binary_tree_size(tree);
	if (node_sum == power_rangers(height) - 1)
		return (1);
	return (0);
}

/**
 * power_rangers - calculate power of 2, using bitwise method
 * @zords: input power
 * Return: power of 2
 */
int power_rangers(int zords)
{
	return (2 << zords);
}

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
