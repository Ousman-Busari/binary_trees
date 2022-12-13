#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the root of the tree whose height is to be measured
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l = 0, h_r = 0;

	if (tree)
	{
		h_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		h_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return (h_l > h_r ? h_l : h_r);
	}
	return (0);
}
