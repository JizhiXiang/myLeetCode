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
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> visit;
		queue<pair<TreeNode*,int>> Q;
		if (root)
		{
			Q.push(make_pair(root,0));
		}
		while (!Q.empty())
		{
			TreeNode* node = Q.front().first;
			int depth = Q.front().second;
			Q.pop();
			if (depth==visit.size())
			{//那一层的第一个
				visit.push_back(node->val);
			}
			else{
				visit[depth] = node->val;
			}
			if (node->left)
			{
				Q.push(make_pair(node->left,depth+1));
			}
			if (node->right)
			{
				Q.push(make_pair(node->right,depth+1));
			}
		}
		return visit;
	}
};

//199.Binary Tree Right Side View
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
	vector<int> result;
	result = solve.rightSideView(&a);
	for (int i=0;i<result.size();i++)
	{
		printf("%d ",result[i]);
	}
	system("pause");
	return 0;
}