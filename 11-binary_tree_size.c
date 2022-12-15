#include "binary_trees.h"

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: measured size, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t size = 1;

		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		return (size);
	}

	return (0);
}
