#define _CRT_SECURE_NO_WARNINGS 1
/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

3
/ \
4   5
/ \
1   2
给定的树 t：

4
/ \
1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

3
/ \
4   5
/ \
1   2
/
0
给定的树 t：

4
/ \
1   2
返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

bool isSameTree(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 != NULL)
		return false;

	if (t1 != NULL && t2 == NULL)
		return false;

	if (t1 == NULL && t2 == NULL)
		return true;

	if (t1->val != t2->val)
		return false;

	return isSameTree(t1->left, t2->left)
		&& isSameTree(t1->right, t2->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL){
		return false;
	}
	if (isSameTree(s, t)){
		return true;
	}
	else{
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
}

/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

3
/ \
9  20
/  \
15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

1
/ \
2   2
/ \
3   3
/ \
4   4
返回 false 。

在真实的面试中遇到过

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int hight(struct TreeNode*t){
	if (t == NULL){
		return 0;
	}
	int leftDepth = hight(t->left);
	int rightDepth = hight(t->right);
	return leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	int leftDepth = hight(root->left);
	int rightDepth = hight(root->right);
	return abs(leftDepth - rightDepth)<2 //绝对值
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}