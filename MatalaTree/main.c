#define _CRT_SECURE_NO_WARNINGS
#include "TreePrintLibrary.h"
#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void main()
{
	BST* bst = (BST*)malloc(sizeof(BST));
	NULL_CHECK(bst);
	init(bst);
	insertBST(bst, 5);
	insertBST(bst, 8);
	insertBST(bst, 2);
	insertBST(bst, 4);
	insertBST(bst, 2);
	insertBST(bst, 5);
	insertBST(bst, 9);
	insertBST(bst, 11);
	insertBST(bst, 2);
	print_ascii_tree(bst->root);
	int N = 7;
	printf("The number in index %d is %d\n", N, findIndexNFromLast(bst, N));
	printTreeInorder(bst);
	(sameHeightLeaves(bst)) ? printf("\nSame height leaves") : printf("\nNot same height leaves");
	destroyBST(bst);
	free(bst);
}
