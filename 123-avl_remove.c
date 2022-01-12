#include "binary_trees.h"

/**
 * avl_remove - remove a node from an AVL Tree
 * @root: AVL root with the node to be removed
 * @value: value to find in the tree
 * Return: new AVL root
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp = NULL, *node = NULL, *imba = NULL;

	if (!root)
		return (NULL);
	if (!root->left && !root->right && root->n == value)
	{
		free(root);
		return (NULL);
	}
	tmp = avl_search(root, value), imba = tmp->parent;
	if (tmp->left && tmp->right && tmp->right->left) /*successor finding*/
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
	if (tmp->parent && (tmp->parent->left == tmp)) /*successor linking*/
		tmp->parent->left = node;
	else if (tmp->parent)
		tmp->parent->right = node;
	if (tmp->parent && node)
		node->parent = tmp->parent;
	else if (node)
		node->parent = NULL, root = node;
	free(tmp);
	if (!imba)
		imba = node;
	avl_chunk_rotator(imba);
	return (root);
}

/**
 * new_root_inorder - find the first node of in-order traversal
 * @tree: pointer to the root node of the AVL to traverse
 * Return: pointer to the node, or null
 */
avl_t *new_root_inorder(avl_t *tree)
{
	avl_t *current = NULL; /* Morris Traversal, no stack */

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
 * avl_search - search for a value in an AVL Tree
 * @tree: pointer to the root node of the tree to traverse
 * @value: value to store in the new node
 * Return: AVL node of value, or null if failed
 */
avl_t *avl_search(const avl_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (tree->n == value)
			return ((avl_t *)tree);
		if (tree->n > value)
			tree = tree->left;
		if (tree->n < value)
			tree = tree->right;
	}
	return (NULL);
}

/**
 * avl_chunk_rotator - rotate chunk of branches in an AVL tree
 * @tmp: parent of the freshly removed node, or the root.
 */
void avl_chunk_rotator(avl_t *tmp)
{
	int avl_balance;

	while (tmp)
	{
		avl_balance = binary_tree_balance(tmp);
		if (avl_balance > 1)
			binary_tree_rotate_right(tmp); /*case left, rotates right*/
		else if (avl_balance < -1)
			binary_tree_rotate_left(tmp); /*case right, rotates left*/
		avl_balance = binary_tree_balance(tmp);
		if (avl_balance <= 1 && avl_balance >= -1)
			tmp = tmp->parent;
	}
}
