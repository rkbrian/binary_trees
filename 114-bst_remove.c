#include "binary_trees.h"

/**
 * bst_remove - remove a node from a Binary Search Tree
 * @root: BST root to be removed
 * @value: value to find in the tree
 * Return: new BST root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL, *new_root = NULL;

	if (!root)
		return (NULL);
	if (!root->left && !root->right)
	{
		free(root);
		return (NULL);
	}
	tmp = bst_search(root, value);
	new_root = new_root_inorder(root);
	if (tmp->left && tmp->left != new_root)
		tmp->left->parent = new_root;
	if (tmp->right && tmp->right != new_root)
		tmp->right->parent = new_root;
	new_root->parent = NULL;
	new_root->left = tmp->left;
	new_root->right = tmp->right;
	free(root);
	return (new_root);
}

/**
 * new_root_inorder - find the first node of in-order traversal
 * @tree: pointer to the root node of the BST to traverse
 * Return: pointer to the node, or null
 */
bst_t *new_root_inorder(bst_t *tree)
{
	if (tree)
		new_root_inorder(tree->left);
	if (!tree->left && !tree->right)
		return (tree);
	if (tree)
		new_root_inorder(tree->right);
	return (NULL);
}
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
