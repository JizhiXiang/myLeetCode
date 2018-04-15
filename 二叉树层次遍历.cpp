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

#include <queue>
void BFS_print(TreeNode *root){
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		TreeNode *node = Q.front();
		printf("%d ",node->val);
		Q.pop();
		if (node->left)
		{
			Q.push(node->left);
		}
		if (node->right)
		{
			Q.push(node->right);
		}
	}
}

//114.
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

	BFS_print(&a);
	system("pause");
	return 0;
}