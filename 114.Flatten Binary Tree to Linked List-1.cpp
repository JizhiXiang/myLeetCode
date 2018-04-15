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
		vector<TreeNode*> node_vec;
		preoder(root,node_vec);
		for (int i=1;i<node_vec.size();i++)
		{
			node_vec[i-1]->left = NULL;
			node_vec[i-1]->right = node_vec[i];
		}
	}
private:
	void preoder(TreeNode *node,vector<TreeNode*> &node_vec){
		if (!node)
		{
			return;
		}
		node_vec.push_back(node);
		preoder(node->left,node_vec);
		preoder(node->right,node_vec);
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
	b.left = &e;
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