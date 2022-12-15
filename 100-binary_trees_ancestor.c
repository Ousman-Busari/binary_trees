#include "binary_trees.h"

binary_tree_t *lowest_common_ancestor(const binary_tree_t *first,
				      const binary_tree_t *second);
size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: the pointer to the node whose depth is to be measured.
 *
 * Return: 0 if tree is NULL, or the depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (-1);

	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: the pointer to the first node.
 * @second: the pointer to the second node.
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes,
 * or NULL if ancestor not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first, depth_second;
	binary_tree_t *tmp = NULL;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first < depth_second)
		tmp = lowest_common_ancestor(first, second);
	else
		tmp = lowest_common_ancestor(second, first);
	return (tmp);
}

/**
 * lowest_common_ancestor - finds the lowest common ancestor of two
 *                          nodes in a binary tree
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL if no common ancestor
 */
binary_tree_t *lowest_common_ancestor(const binary_tree_t *first,
				      const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);
	while (first)
	{
		tmp = (binary_tree_t *)second;
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
