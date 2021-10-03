#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int bad_beast;
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
		tmp = queue_remove(queen, tmp);
		if (tmp)
		{
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
	if (bad_beast > 0)
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
 * queue_remove - extract node data from queue
 * @queen: the queue
 * @node: tree node of the same depth (from root)
 * Return: node pointer with acquired data if success, null if failed
 */
binary_tree_t *queue_remove(queue_q *queen, const binary_tree_t *node)
{
	if ((queen->tail + 1) % MAX_Q_SIZE == queen->head) /* if queue is empty */
		return (NULL);
	node = queen->queue_arr[queen->head];
	queen->head = (queen->head + 1) % MAX_Q_SIZE;
	return ((binary_tree_t *)node);
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
