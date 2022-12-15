#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the pointer to the root node of the bainary tree
 *
 * Return: 1 if perfect, 0 therwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, leaf_n_height_rel = 1, leaves;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	leaves = binary_tree_leaves(tree);

	while (height)
	{
		leaf_n_height_rel *= 2;
		height--;

	}

	if (leaves == leaf_n_height_rel)
		return (1);
	return (0);
}
