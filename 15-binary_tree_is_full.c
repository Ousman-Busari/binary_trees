#include "binary_trees.h"

/**
 * is_full_recursive - checks if a binary tree is full recursively
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if full, 0 otherwise
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && !tree->right) ||
		    (!tree->left && tree->right) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}

	return (1);
}

/**
 * binary_tree_is_full - checks is a binary tree is full
 * @tree: the pointer to the root node of the binary tree
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full_recursive(tree));
}
