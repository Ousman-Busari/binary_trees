#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
	  levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);

/**
 * create_node - create a new levelorder_queue_t node using
 *               anode from a binary tree
 * @node: pointer to the node in a binary tree
 *
 * Return: pointer to newly created node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	if (!node)
		return (NULL);

	new = malloc(sizeof(levelorder_queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - frees a levelorder_queue_t queue
 * @head: the pointer to the head of the queue
 *
 * Return: Nothing
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - pushes on a new node to a levelorder_queue_t queue
 * @node: pointer to the new node to be pushed
 * @head: pointer to the pointer of the queue head
 * @tail: pointer to the pointet of the queue tail
 *
 * Return: Nothing
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
	  levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (!new)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - pops the head of a levelorder_queue_t queue
 * @head: double pointer to the head of the queue
 *
 * Return: Nothing
 */
void pop(levelorder_queue_t **head)
{

	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (!tree)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		exit(1);

	while (head)
	{
		if (head->node->left)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}

	return (1);
}
