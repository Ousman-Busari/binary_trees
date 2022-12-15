#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves in a binary tree
 * @tree: the pointer to the root node of the binary tree
 *
 * Return: the count, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t count;

		count = (!tree->left && !tree->right) ? 1 : 0;
		count += binary_tree_leaves(tree->left);
		count += binary_tree_leaves(tree->right);
		return (count);
	}

	return (0);
}
