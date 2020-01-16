#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
树的几个重要概念：
    1.节点的度：一个节点含有的子树的个数称为该节点的度
	2.叶节点或终端节点：度为0的节点成为叶节点；
二叉树的概念：
    一颗二叉树是结点的一个有限集合，该集合或者为空，或者是由一个根节
	加上两颗别称为左子树和右子树的二叉树组成
	    特点：
	1.每个结点最多有两颗子树，即二叉树不存在度大于二的结点
	2.二叉树的子树有左右之分，其子树的次序不能颠倒
	    性质：
    1.若规定根节点的层数为0，则一颗非空二叉树的第i层最多有2^i个结点
	2.若规定只有根节点的二叉树深度为0，则深度为h的二叉树的最大结点
	是2^(h+1)-1。
	3.对任何一棵二叉树，如果其叶节点个数为n0，度为2的非叶节点个数为
	n2，则有n0 = n2+1
	4.具有n个结点的完全二叉树的深度为h = log2(n+1).（第0层深度为1）
    5.对于具有n个结点的完全二叉数树，如果按照从上至下从左至右的数组
	顺序对所有的节点从0开始编号 则对于序号为i的节点有：
	若i>0，i位置上的双亲序号为（i-1）/2；i = 0，i为根节点，无双亲节
	 点。
	若2i+1<n,左孩子序号：2i+1
	若2i+2<n，右孩子序号：2i+2

二叉树的遍历：
    前序遍历：根左右
	中序遍历：左根右
	后序遍历：左右根
*/
//链式存储的二叉树定义
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode{
	struct BinaryTreeNode* _pLeft;//指向当前节点的左孩子
	struct BinaryTreeNode* _pRight;//指向当前节点的右孩子
	BTDataType _data;//当前节点值域
}BTNode;
//通过前序遍历打印输出二叉树
void BinaryTreePrint(BTNode* root);

//通过前序遍历的数组“ABD##E#H##CF##G##”构建二叉树
BTNode* BinaryTreeCreate(int n, BTDataType** pi);

//二叉树的销毁
void BinaryTreeDestory(BTNode** root);

//二叉树的节点个数
int BinaryTreeSize(BTNode* root);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);

//二叉树第k层节点的个数  以根节点为第1层计算
int BinaryTreeLevelkSize(BTNode* root, int k);

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);