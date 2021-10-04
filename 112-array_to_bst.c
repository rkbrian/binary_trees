#include "binary_trees.h"

/**
 * array_to_bst - build a Binary Search Tree from an array
 * @array: array of integers
 * @size: size of BST
 * Return: new BST root
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *beast = NULL;
	int i, num;

	if (!array || size <= 0)
		return (NULL);
	num = size;
	for (i = 0; (i < num) && (array[i] != '\0'); i++)
	{
		bst_insert(&beast, array[i]);
	}
	return (beast);
}
