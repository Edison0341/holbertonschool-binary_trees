#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: measure of the balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lsubtree = 0, rsubtree = 0;

	if (tree == NULL)
		return (0);

	lsubtree = binary_tree_height(tree->left);
	rsubtree = binary_tree_height(tree->right);

	return (lsubtree - rsubtree);
}
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
