#include "stdafx.h"
#include <stdlib.h>
#include <vector>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};

void preorder_print(TreeNode *node,int layer){
	if (!node)
	{
		return;
	}
	for (int i=0;i<layer;i++)
	{
		printf("------");
	}
	printf("[%d]\n",node->val);
	preorder_print(node->left,layer+1);
	preorder_print(node->right,layer+1);
}

void mid_print(TreeNode *node){
	if (!node)
	{
		return ;
	}
	mid_print(node->left);
	printf("[%d] ",node->val);
	mid_print(node->right);
}

void late_print(TreeNode *node){
	if (!node)
	{
		return ;
	}
	late_print(node->left);
	late_print(node->right);
	printf("[%d] ",node->val);
}

//¶þ²æÊ÷µÄ±éÀú
int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	preorder_print(&a,0);
	printf("\n");
	mid_print(&a);
	printf("\n");
	late_print(&a);
	system("pause");
	return 0;
}