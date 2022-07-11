#ifndef _BST_ADT_H
#define _BST_ADT_H

#define NULL_CHECK(a);\
do{\
if (a == NULL) {\
printf("allocation failed");\
exit(1);\
}\
} while (0)
typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;


#endif // !_BST_ADT_H

void insertBST(BST* bst, int value);
void init(BST* bst);
void insert(TreeNode* root, TreeNode* node);
void printTreeInorder(BST* bst);
void inorder(TreeNode* node);
void destroyBST(BST* bst);
void destroy(TreeNode* node);
int findIndexNFromLast(BST* bst, int N);
int findIndexNFromLasthelper(TreeNode* node, int N);
int sameHeightLeaves(BST* bst);
int checkHight(TreeNode* node, int level, int* currlevel);


