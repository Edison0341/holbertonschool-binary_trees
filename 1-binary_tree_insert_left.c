#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: is the value to store in the new mode
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	if (parent == NULL)
		return (NULL);

	new_child = malloc(sizeof(binary_tree_t));

	if (new_child == NULL)
		return (NULL);

	new_child->n = value;
	new_child->parent = parent;
	new_child->left = parent->left;
	new_child->right = NULL;

	if (parent->left != NULL)
		parent->left->parent = new_child;

	parent->left = new_child;

	return (new_child);
}
