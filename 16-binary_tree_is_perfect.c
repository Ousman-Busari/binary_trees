#include "binary_trees.h"
size_t subtree_height(const binary_tree_t *type);
int subtrees_heights_are_equal(const binary_tree_t *type);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the pointer to the root node of the bainary tree
 *
 * Return: 1 if perfect, 0 therwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left && tree->right &&
		    subtrees_heights_are_equal(tree))
			return (1);
		return (0);
	}

	return (0);
}

/**
 * subtree_height - measures the height of a binary subtree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: measured height, or -1 if tree is NULL
 */
size_t subtree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = tree->left ? 1 + subtree_height(tree->left) : 0;
		r = tree->right ? 1 + subtree_height(tree->right) : 0;
		return (l > r ? l : r);
	}

	return (-1);
}

/**
 * subtrees_heights_are_equal - checks if the heights of subtrees of a
 *                              binary tree node are equal
 * @tree: the pointer to the node whose subtrees heights are to be compared
 *
 * Return: 1 if they are equal, 0 otherwise
 */
int subtrees_heights_are_equal(const binary_tree_t *tree)
{
	if (subtree_height(tree->left) == subtree_height(tree->right))
		return (1);
	return (0);
}
