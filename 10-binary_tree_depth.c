#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: the pointer to the root node of the tree
 *
 * Return: measured depth, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t depth = 0;

		depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
		return (depth);
	}

	return (0);
}
