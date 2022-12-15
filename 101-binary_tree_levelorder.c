#include "binary_trees.h"

void func_traverse_current_level(const binary_tree_t *tree,
				 void (*func)(int), size_t level);
size_t binary_tree_height(const binary_tree_t *tree);

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
 * func_traverse_current_level - traverses through a binary tree using
 *                               level-order and call a fucntion on each node
 * @tree: pointer to the root node on the binary tree
 * @func: pointer to the func to be called on each node
 * @level: the current level of the tree to traverse
 *
 * Return: Nothing
 */
void func_traverse_current_level(const binary_tree_t *tree, void(*func)(int),
				 size_t level)
{
	if (!tree || !func)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		func_traverse_current_level(tree->left, func, level - 1);
		func_traverse_current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 *                          level-order treaversal
 * @tree: the pointer to the root node of the binary tree to traverse
 * @func: pointer to the function to be called on each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void(*func)(int))
{
	size_t i, level;

	if (!tree || !func)
		return;

	level = binary_tree_height(tree);
	for (i = 0; i <= level; i++)
		func_traverse_current_level(tree, func, i);
}
