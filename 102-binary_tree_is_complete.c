#include "binary_trees.h"

/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_q *queen;
	binary_tree_t *tmp = NULL;

	if (func && tree)
	{
		queen = malloc(sizeof(queue_q));
		if (!queen)
			return;
		memset(queen, 0, sizeof(queue_q));
		queen->head = 1, queen->tail = 0;
		queue_store(queen, tree);
		while ((queen->tail + 1) % MAX_Q_SIZE != queen->head)
		{
			tmp = queue_remove(queen, tmp);
			if (tmp)
			{
				func(tmp->n);
				if (tmp->left)
					queue_store(queen, tmp->left);
				if (tmp->right)
					queue_store(queen, tmp->right);
			}
		}
		free(queen);
	}
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
 * Return: 0 if success, 1 if failed
 */
binary_tree_t *queue_remove(queue_q *queen, const binary_tree_t *node)
{
	if ((queen->tail + 1) % MAX_Q_SIZE == queen->head) /* if queue is empty */
		return (NULL);
	node = queen->queue_arr[queen->head];
	queen->head = (queen->head + 1) % MAX_Q_SIZE;
	return ((binary_tree_t *)node);
}
