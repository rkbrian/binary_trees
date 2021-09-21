#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: ptr to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp = NULL, *newnode = NULL;

	if (parent == NULL)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	tmp = parent;
	newnode->n = value;
	newnode->left = tmp->left;
	if (tmp->left)
		tmp->left->parent = newnode;
	newnode->parent = tmp;
	tmp->left = newnode;
	return (newnode);
}
