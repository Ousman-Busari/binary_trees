#include "binary_trees.h"

/**
 * binary_tree_insert_right - create and insert a new node to
 *                            the right of a parent node
 * @parent: the parent node of the node to be inserted
 * @value: the value of the new node to be inserted
 *
 * Return: pointer to the newly created node, or NULL if failed
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right)
	{
		tmpNode = parent->right;
		parent->right = newNode;
		newNode->right = tmpNode;
		tmpNode->parent = newNode;
	}
	else
		parent->right = newNode;

	return (newNode);
}
