#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: pointer to the root node of the tree to traverse
 * @value: value to store in the new node
 * Return: ptr to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(*tree, value));
	tmp = *tree;
	while (tmp)
	{
		if ((tmp->n > value) && tmp->left)
			tmp = tmp->left;
		else if ((tmp->n < value) && tmp->right)
			tmp = tmp->right;
		else if (tmp->n > value)
			return (tmp->left = binary_tree_node(tmp, value));
		else if (tmp->n < value)
			return (tmp->right = binary_tree_node(tmp, value));
		else if (tmp->n == value)
			break;
	}
	return (NULL);
}
