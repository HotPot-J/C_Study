#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"
int main(){
	char *a = "ABD##E#H##CF##G##";
	BTNode *root;
	int size = 0; 
	int LeafSize = 0;
	int LevelkSize = 0;
	root= BinaryTreeCreate(sizeof(a)-1,&a);
	BinaryTreePrint(root);
	size = BinaryTreeSize(root);
	LeafSize = BinaryTreeLeafSize(root);
	LevelkSize =  BinaryTreeLevelkSize(root, 1);
	printf("\n%d\n", size);
	printf("%d\n", LeafSize);
	printf("%d\n", LevelkSize);
	BinaryTreeDestory(&root);
	return 0 ;
}




















