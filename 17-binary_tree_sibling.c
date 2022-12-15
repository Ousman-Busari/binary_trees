#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: pointer to the node to finsd the sibling
 *
 * Return: pointer to the sibling node
 *         NULL if node is NULL or node parent is NULL or no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling =  NULL;

	if (node && node->parent)
	{
		if (node->parent->left == node && node->parent->right)
			sibling = node->parent->right;
		if (node->parent->right == node && node->parent->left)
			sibling = node->parent->left;
	}

	return (sibling);
}
