#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
���ļ�����Ҫ���
    1.�ڵ�Ķȣ�һ���ڵ㺬�е������ĸ�����Ϊ�ýڵ�Ķ�
	2.Ҷ�ڵ���ն˽ڵ㣺��Ϊ0�Ľڵ��ΪҶ�ڵ㣻
�������ĸ��
    һ�Ŷ������ǽ���һ�����޼��ϣ��ü��ϻ���Ϊ�գ���������һ������
	�������ű��Ϊ���������������Ķ��������
	    �ص㣺
	1.ÿ���������������������������������ڶȴ��ڶ��Ľ��
	2.������������������֮�֣��������Ĵ����ܵߵ�
	    ���ʣ�
    1.���涨���ڵ�Ĳ���Ϊ0����һ�ŷǿն������ĵ�i�������2^i�����
	2.���涨ֻ�и��ڵ�Ķ��������Ϊ0�������Ϊh�Ķ������������
	��2^(h+1)-1��
	3.���κ�һ�ö������������Ҷ�ڵ����Ϊn0����Ϊ2�ķ�Ҷ�ڵ����Ϊ
	n2������n0 = n2+1
	4.����n��������ȫ�����������Ϊh = log2(n+1).����0�����Ϊ1��
    5.���ھ���n��������ȫ����������������մ������´������ҵ�����
	˳������еĽڵ��0��ʼ��� ��������Ϊi�Ľڵ��У�
	��i>0��iλ���ϵ�˫�����Ϊ��i-1��/2��i = 0��iΪ���ڵ㣬��˫�׽�
	 �㡣
	��2i+1<n,������ţ�2i+1
	��2i+2<n���Һ�����ţ�2i+2

�������ı�����
    ǰ�������������
	��������������
	������������Ҹ�
*/
//��ʽ�洢�Ķ���������
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode{
	struct BinaryTreeNode* _pLeft;//ָ��ǰ�ڵ������
	struct BinaryTreeNode* _pRight;//ָ��ǰ�ڵ���Һ���
	BTDataType _data;//��ǰ�ڵ�ֵ��
}BTNode;
//ͨ��ǰ�������ӡ���������
void BinaryTreePrint(BTNode* root);

//ͨ��ǰ����������顰ABD##E#H##CF##G##������������
BTNode* BinaryTreeCreate(int n, BTDataType** pi);

//������������
void BinaryTreeDestory(BTNode** root);

//�������Ľڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

//��������k��ڵ�ĸ���  �Ը��ڵ�Ϊ��1�����
int BinaryTreeLevelkSize(BTNode* root, int k);

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);