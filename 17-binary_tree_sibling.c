#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @tree: pointer to the root node of the tree to traverse
 * Return: pointer to the sibling node, or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	if (node->parent->right == node)
		return (node->parent->left);
	return (NULL);
}
