#include "binary_trees.h"

/**
 * array_to_avl - build an AVL Tree from an array
 * @array: array of integers
 * @size: size of AVL Tree
 * Return: new AVL root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *avl_root = NULL;
	int i, num;

	if (!array || size <= 0)
		return (NULL);
	num = size;
	for (i = 0; (i < num) && (array[i] != '\0'); i++)
	{
		avl_insert(&avl_root, array[i]);
	}
	return (avl_root);
}
