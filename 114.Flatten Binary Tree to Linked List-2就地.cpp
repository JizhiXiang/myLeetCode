#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};

class Solution{
public:
	void flatten(TreeNode *root){
		TreeNode *last = NULL;
		preorder(root,last);
	}
private:
	void preorder(TreeNode *node,TreeNode *&last){
		if (!node)
		{
			return;
		}
		if (!node->left&&!node->right)
		{
			last = node;
			return;
		}
		TreeNode *left = node->left;
		TreeNode *right = node->right;
		TreeNode *last_left = NULL;
		TreeNode *last_right = NULL;
		if (left)
		{
			preorder(left,last_left);
			node->left = NULL;
			node->right = left;
			last = last_left;
		}
		if (right)
		{
			preorder(right,last_right);
			if (last_left)//Èô×ó±ß´æÔÚ
			{
				last_left->right = right;
			}
			last = last_right;
		}
	}
};

//114.Flatten Binary Tree to Linked List
int main(){
	TreeNode a(3);

	TreeNode b(5);
	TreeNode c(1);

	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode g(8);

	TreeNode h(7);
	TreeNode i(4);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	e.left = &h;
	e.right = &i;

	Solution solve;
	solve.flatten(&a);
	TreeNode *head = &a;
	while(head){		
		printf("%d ",head->val);
		head = head->right;
	}
/*	for (int i=0;i<result.size();i++)
	{
		for (int j=0;j<result[i].size();j++)
		{
			printf("[%d] ",result[i][j]);
		}
		printf("\n");
	}*/
	system("pause");
	return 0;
}