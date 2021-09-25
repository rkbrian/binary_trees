#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node (sibling of node's parent)
 * @node: pointer to the node
 * Return: pointer to the sibling node, or null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || node->parent == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node
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
