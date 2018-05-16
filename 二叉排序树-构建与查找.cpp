#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void BST_insert(TreeNode *node,TreeNode *insert_node){
	if (insert_node->val < node->val)
	{
		if (node->left)//左子树不空
		{
			BST_insert(node->left, insert_node);
		}else{
			node->left = insert_node;
		}
	}else{
		if (node->right)
		{BST_insert(node->right,insert_node);
		}else{
			node->right = insert_node;
		}
	}
}
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

bool BST_search(TreeNode *node,int value){
	if (value == node->val)
	{
		return true;
	}
	else if (value < node->val)
	{
		if (node->left)
		{//如果有左子树
			return BST_search(node->left,value);
		}else{
			return false;
		}		
	}else if (value > node->val)
	{
		if (node->right)
		{
			return BST_search(node->right,value);
		}else {
			return false;
		}
	}
}

//二叉排序树-构建与查找
int main(){
	TreeNode root(8);
	vector<TreeNode *> node_vec;
	int test[] = {3,10,1,6,15};
	for (int i=0;i<5;i++)
	{
		node_vec.push_back(new TreeNode(test[i]));
	}
	for (int i=0;i<node_vec.size();i++)
	{
		BST_insert(&root,node_vec[i]);
	}
	preorder_print(&root,0);

	//查找
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	for (int i=0;i<20;i++)
	{
		if (BST_search(&a,i))
		{
			printf("%d is in the BST.\n",i);
		}else{
			printf("%d is not in the BST.\n",i);
		}
	}
	system("pause");
	return 0;
}