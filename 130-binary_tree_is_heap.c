#include "binary_trees.h"

/**
 * binary_tree_height - measures the height
 * @tree: tree
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
		}
}

/**
 * binary_tree_balance - Measures balance
 * @tree: tree
 * Return: balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * tree_is_perfect - function that says
 * @tree: tree
 * Return: 0 or other number
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not
 * @tree: check
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - checks if a binary tree
 * @tree: check
 * Return: 1  or 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bval;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	bval = binary_tree_balance(tree);
	if (bval == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (bval == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}