#include "binary_trees.h"
size_t subtree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: the measured value, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (subtree_height(tree->left) -
			subtree_height(tree->right));

	return (0);
}

/**
 * subtree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: the measured value, -1 if tree is NULL
 */
size_t subtree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t h_l = 0, h_r = 0;

		h_l += tree->left ? 1 + subtree_height(tree->left) : 0;
		h_r += tree->right ? 1 + subtree_height(tree->right) : 0;
		return (h_l > h_r ? h_l : h_r);
	}

	return (-1);
}
