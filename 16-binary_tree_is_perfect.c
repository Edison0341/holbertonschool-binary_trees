#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: hieght of the binary tree in number
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (tree->right == NULL && tree->left == NULL)
		return (0);

	if (right_height > left_height)
		return (right_height + 1);
	return (left_height + 1);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int r, l;
	size_t height;

	if (tree == NULL)
		return (0);

	l = binary_tree_is_perfect(tree->left);
	r = binary_tree_is_perfect(tree->right);
	height = binary_tree_height(tree);

	if (tree->parent == NULL)
	{
		if (l == r)
			return (1);
		return (0);
	}

	if (height == 0)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
	}

	if (l != r)
		return (0);
	return (l + r + height);
}
