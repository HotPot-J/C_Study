#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
void BinaryTreePrint(BTNode* root){
	if (root){
		printf("%c", root->_data);
		BinaryTreePrint(root->_pLeft);
		BinaryTreePrint(root->_pRight);
	}
}
BTNode* BinaryTreeCreate(int n, BTDataType** pi){
	if (**pi == '#' || pi > pi + n-1){
		(*pi)++;
		return NULL;
	}
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = **pi;
	(*pi)++;
	root->_pLeft = BinaryTreeCreate(n, pi);
	root->_pRight = BinaryTreeCreate(n, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root){ 
	if (*root){
		BinaryTreeDestory(&((*root)->_pLeft));
		BinaryTreeDestory(&((*root)->_pRight));
		free(*root);
		root = NULL;
	}
}

int BinaryTreeSize(BTNode* root){
	if (root==NULL){
		return 0;
	}
	else{
		return BinaryTreeSize(root->_pLeft) + BinaryTreeSize(root->_pRight) + 1;
	}
}

int BinaryTreeLeafSize(BTNode* root){
		if (root == NULL){
			return 0;
		}
		else if (root->_pLeft == NULL&&root->_pRight == NULL){ //如何判断是叶子
			return 1;
		}
		else{
			return BinaryTreeLeafSize(root->_pLeft) + BinaryTreeLeafSize(root->_pRight);
		}
}
int BinaryTreeLevelkSize(BTNode* root, int k){
	//二叉树第k层节点的个数
	if (root == NULL){
		return 0;
	}
	else if (k==1){
			return 1;

	}
	else {
		k--;
		return  BinaryTreeLevelkSize(root->_pLeft, k) + BinaryTreeLevelkSize(root->_pRight, k);
	}
}
