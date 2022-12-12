#include "binary_trees.h"

/**
 * binary_tree_insert_left - create and insert a new node to
 *                           the left of a parent node
 * @parent: the parent node of the node to be inserted
 * @value: the value of the new node to be inserted
 *
 * Return: pointer to the newly created node, or NULL if failed
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode, *tmpNode;

	if (!parent)
		return (NULL);

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent->left)
	{
		tmpNode = parent->left;
		parent->left = newNode;
		newNode->left = tmpNode;
		tmpNode->parent = newNode;
	}
	else
		parent->left = newNode;

	return (newNode);
}
