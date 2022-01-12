#include "binary_trees.h"

/**
 * avl_insert - function that inserts a value in an AVL Tree
 * @tree: pointer to the root node of the tree to traverse
 * @value: value to store in the new node
 * Return: ptr to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int lower_node = 0;
	avl_t *tmp = NULL, *ret_node = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(*tree, value));
	tmp = *tree;
	while (tmp)
	{
		if ((tmp->n > value) && tmp->left)
			tmp = tmp->left;
		else if ((tmp->n < value) && tmp->right)
			tmp = tmp->right;
		else if (tmp->n == value)
			return (NULL);
		else if (tmp->n > value) /*insert to the left*/
		{
			tmp->left = binary_tree_node(tmp, value);
			ret_node = tmp->left, lower_node = 1;
			break;
		}
		else if (tmp->n < value) /*insert to the right*/
		{
			tmp->right = binary_tree_node(tmp, value);
			ret_node = tmp->right, lower_node = -1;
			break;
		}
	}
	avl_rotator(tmp, lower_node);
	while ((*tree)->parent)
		*tree = (*tree)->parent;
	return (ret_node);
}

/**
 * avl_rotator - rotate freshly inserted AVL tree if necessary
 * @tmp: parent of the freshly inserted node.
 * @lower_node: flag indicating the position of the freshly inserted node,
 *  1 if on left of its parent, -1 if on right
 */
void avl_rotator(avl_t *tmp, int lower_node)
{
	int avl_balance;

	while (tmp)
	{
		avl_balance = binary_tree_balance(tmp);
		if (avl_balance > 1 && lower_node == 1)
			binary_tree_rotate_right(tmp); /*case left left, rotates right*/
		else if (avl_balance > 1 && lower_node == -1)
		{
			binary_tree_rotate_left(tmp->left);
			binary_tree_rotate_right(tmp); /*case left right, rotates left then right*/
		}
		else if (avl_balance < -1 && lower_node == 1)
		{
			binary_tree_rotate_right(tmp->right);
			binary_tree_rotate_left(tmp); /*case right left, rotates right then left*/
		}
		else if (avl_balance < -1 && lower_node == -1)
			binary_tree_rotate_left(tmp); /*case right right, rotates left*/
		avl_balance = binary_tree_balance(tmp);
		if (avl_balance <= 1 && avl_balance >= -1)
			tmp = tmp->parent;
	}
}
