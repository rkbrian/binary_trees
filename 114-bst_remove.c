#include "binary_trees.h"

/**
 * bst_remove - remove a node from a Binary Search Tree
 * @root: BST root to be removed
 * @value: value to find in the tree
 * Return: new BST root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL, *node = NULL;

	if (!root)
		return (NULL);
	if (!root->left && !root->right)
	{
		free(root);
		return (NULL);
	}
	tmp = bst_search(root, value);
	if (tmp->left && tmp->right && tmp->right->left)
	{
		node = new_root_inorder(tmp);
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		tmp->left->parent = node, tmp->right->parent = node;
		node->left = tmp->left, node->right = tmp->right;
	}
	else if (tmp->right)
	{
		node = tmp->right, node->parent = tmp->parent, node->left = tmp->left;
		if (tmp->left)
			tmp->left->parent = node;
	}
	else if (tmp->left)
		node = tmp->left, node->parent = tmp->parent;

	if (tmp->parent && (tmp->parent->left == tmp))
		tmp->parent->left = node;
	else if (tmp->parent)
		tmp->parent->right = node;
	if (tmp->parent && node)
		node->parent = tmp->parent;
	else if (node)
		node->parent = NULL, root = node;
	free(tmp);
	return (root);
}

/**
 * new_root_inorder - find the first node of in-order traversal
 * @tree: pointer to the root node of the BST to traverse
 * Return: pointer to the node, or null
 */
bst_t *new_root_inorder(bst_t *tree)
{
	bst_t *current = NULL; /* Morris Traversal, no stack */

	current = tree;
	if (current->right)
	{
		current = current->right;
		while (current)
		{
			if (current->left)
				current = current->left;
			else
				return (current);
			if (current && (current->left == NULL) && (current->right == NULL))
				break;
		}
	}
	return (current);
}

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
