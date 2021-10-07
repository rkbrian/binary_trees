#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: return 1 if tree is a valid AVL, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bad_beast = 0, avl_balance;
	queue_q *queen;
	binary_tree_t *tmp = NULL;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	queen = malloc(sizeof(queue_q));
	if (!queen)
		return (0);
	memset(queen, 0, sizeof(queue_q));
	queen->head = 1, queen->tail = 0, queue_store(queen, tree);
	while ((queen->tail + 1) % MAX_Q_SIZE != queen->head)
	{
		if ((queen->tail + 1) % MAX_Q_SIZE == queen->head) /* if queue is empty */
			tmp = NULL;
		tmp = queen->queue_arr[queen->head];
		queen->head = (queen->head + 1) % MAX_Q_SIZE;
		if (tmp)
		{
			avl_balance = binary_tree_balance(tmp);
			if (avl_balance > 1 || avl_balance < -1)
				break;
			bad_beast = beast_wars(tmp->left, tmp->n, 0);
			if (bad_beast > 0)
				break;
			bad_beast = beast_wars(tmp->right, tmp->n, 1);
			if (bad_beast > 0)
				break;
			if (tmp->left)
				queue_store(queen, tmp->left);
			if (tmp->right)
				queue_store(queen, tmp->right);
		}
	}
	free(queen);
	if (avl_balance > 1 || avl_balance < -1 || bad_beast > 0)
		return (0);
	return (1);
}

/**
 * queue_store - store data to queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: 0 if success, 1 if failed
 */
int queue_store(queue_q *queen, const binary_tree_t *node)
{
	if ((queen->tail + 2) % MAX_Q_SIZE == queen->head) /* if queue is full */
		return (1);
	queen->tail = (queen->tail + 1) % MAX_Q_SIZE;
	queen->queue_arr[queen->tail] = (binary_tree_t *)node;
	return (0);
}

/**
 * beast_wars - compare all values in a tree with root value for BST validity
 * @tree: pointer to a child of the root node of the tree to traverse
 * @root_num: root node value
 * @direction: 0 if node is left child, 1 for right child
 * Return: 0 for valid bst, 1 otherwise
 */
int beast_wars(const binary_tree_t *tree, int root_num, int direction)
{
	int i = 0;

	if (!tree)
		return (0);
	if (direction == 0 && tree->n >= root_num)
		i++;
	else if (direction == 1 && tree->n <= root_num)
		i++;
	i = i + beast_wars(tree->left, root_num, direction);
	i = i + beast_wars(tree->right, root_num, direction);
	return (i);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: balance factor of binary tree, or 0 if tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_tr, right_tr;

	if (!tree)
		return (0);
	if (!tree->left)
		left_tr = 0;
	else
		left_tr = binary_tree_height(tree->left) + 1;
	if (!tree->right)
		right_tr = 0;
	else
		right_tr = binary_tree_height(tree->right) + 1;
	return (left_tr - right_tr);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: height of binary tree, or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i, lefti, righti;

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
