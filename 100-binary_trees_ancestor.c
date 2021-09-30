#include "binary_trees.h"

/**
 * binary_tree_ancestor - find the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	int fir_depth, sec_depth;
	const binary_tree_t *tmp_fir = first, *tmp_sec = second;

	if (!first || !second) /*null ptr check*/
		return (NULL);
	else if (first == second) /*same node check*/
		return ((binary_tree_t *)tmp_fir);
	while (tmp_fir->parent)
		tmp_fir = tmp_fir->parent;
	while (tmp_sec->parent)
		tmp_sec = tmp_sec->parent;
	if (tmp_fir != tmp_sec) /*not on the same tree*/
		return (NULL);
	if (first->parent == NULL) /*root check*/
		return ((binary_tree_t *)first);
	else if (second->parent == NULL)
		return ((binary_tree_t *)second);
	fir_depth = binary_tree_depth(first);
	sec_depth = binary_tree_depth(second);
	tmp_fir = first, tmp_sec = second;
	if (fir_depth == sec_depth)
		return (same_gen(first, second));
	else if (fir_depth > sec_depth)
	{
		while (fir_depth > sec_depth)
			tmp_fir = tmp_fir->parent, fir_depth--;
		return (same_gen(tmp_fir, second));
	}
	else
	{
		while (fir_depth < sec_depth)
			tmp_sec = tmp_sec->parent, sec_depth--;
	}
	return (same_gen(first, tmp_sec));
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: depth of binary tree, or 0 if tree is null
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;

	if (tree)
	{
		while (tree->parent)
			tree = tree->parent, i++;
		return (i);
	}
	return (0);
}

/**
 * same_gen - find the closest ancestor between the kids in the same generation
 * @gen_a: pointer to the first node
 * @gen_b: pointer to the second node
 * Return: pointer to the closest ancestor
 */
binary_tree_t *same_gen(const binary_tree_t *gen_a, const binary_tree_t *gen_b)
{
	while (gen_a != gen_b)
		gen_a = gen_a->parent, gen_b = gen_b->parent;
	return ((binary_tree_t *)gen_a);
}
