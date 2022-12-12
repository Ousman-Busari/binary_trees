#include "binary_trees.h"

/**
 * binary_tree_node - creates a new nodes in a binary tree
 * @parent: the parent node of the new node to be created
 * @value: the value of the new node
 *
 * Return: pointer to the newly created node, or NULL if failed
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
