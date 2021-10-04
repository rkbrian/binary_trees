#include "binary_trees.h"

/**
 * bst_search - search for a value in a Binary Search Tree
 * @tree: pointer to the root node of the tree to traverse
 * @value: value to store in the new node
 * Return: BST node of value, or null if failed
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			tree = tree->left;
		if (tree->n < value)
			tree = tree->right;
	}
	return (NULL);
}
