#include "binary_trees.h"

/**
 * sorted_array_to_avl - build an AVL Tree from a sorted array.
 *  Note: no duplicate value, 2 functions max in this file.
 * @array: array of integers
 * @size: size of AVL Tree
 * Return: new AVL root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_root = NULL;
	int num = size;

	if (!array || size <= 0)
		return (NULL);
	avl_root = build_avl(array, 0, num - 1);
	return (avl_root);
}

/**
 * build_avl - build AVL tree to distribute int array values, no rotation
 * @array: array of integers
 * @start: start of index region for the target array value
 * @end: end of index region for the target array value
 * Return: new node
 */
avl_t *build_avl(int *array, int start, int end)
{
	avl_t *node;
	int mid = (start + end) / 2;

	if (start <= end)
	{
		node = binary_tree_node(NULL, array[mid]);
		if (!node)
			return (NULL);
		node->left = build_avl(array, start, mid - 1);
		if (node->left)
			node->left->parent = node;
		node->right = build_avl(array, mid + 1, end);
		if (node->right)
			node->right->parent = node;
		return (node);
	}
	return (NULL);
}
