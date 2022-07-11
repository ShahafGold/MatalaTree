#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS


void init(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	TreeNode* node = (TreeNode*)calloc(1, sizeof(TreeNode));
	NULL_CHECK(node);
	node->element = value;
	if (bst->root == NULL)
	{
		bst->root = node;
	}
	else
		insert(bst->root, node);
}
void insert(TreeNode* root, TreeNode* node)
{
	if (node->element <= root->element) // go LEFT
	{
		if (root->left == NULL)
		{
			root->left = node;
		}
		else
			insert(root->left, node);
	}
	if (node->element > root->element) //  go RIGHT
	{
		if (root->right == NULL)
		{
			root->right = node;
		}
		else
			insert(root->right, node);
	}
}
void printTreeInorder(BST* bst)
{
	if (bst->root == NULL)
	{
		printf("The tree is empty...\n");
	}
	inorder(bst->root); // helper function 
}
void inorder(TreeNode* node) // inorder print
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d,", node->element);
		inorder(node->right);
	}
}
void destroyBST(BST* bst)
{
	if (bst->root == NULL)
	{
		printf("The tree is empty...\n");
	}
	destroy(bst->root);
}
void destroy(TreeNode* node) // posorder free
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

int findIndexNFromLast(BST* bst, int N)
{
	if (N <= 0) // if the N < 0 return
	{
		printf("The number %d is even or less than 0...\n", N);
		return NULL;
	}
	return findIndexNFromLasthelper(bst->root, N);
}
int findIndexNFromLasthelper(TreeNode* node, int N)
{
	// static ints;
	static int temp = 1;
	static int res = 0;
	if (node != NULL)
	{
		// right node
		findIndexNFromLasthelper(node->right, N);
		if (node->right != NULL) temp++;
		if (temp == N)
		{
			res = node->element;
		}
		// left node
		findIndexNFromLasthelper(node->left, N);
		if (node->left != NULL) temp++;
	}
	return res;
}
int checkHight(TreeNode* node, int level, int* currlevel)
{
	// stop recorsia
	if (node == NULL)  return 1;

	// find the a leaf
	if (node->left == NULL && node->right == NULL)
	{
		// the first leaf that found
		if (*currlevel == 0)
		{
			*currlevel = level;
			return 1;
		}

		// compare to level of tree if not the first leaf
		return (level == *currlevel);
	}

	// increse the level and check the other leafs
	return checkHight(node->left, level + 1, currlevel) && checkHight(node->right, level + 1, currlevel);
}

int sameHeightLeaves(BST* bst)
{
	int level = 0, currlevel = 0;
	return checkHight(bst->root, level, &currlevel);//calling the helping function
}
