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
	vector<vector<int>> pathSum(TreeNode *root,int sum){
		int path_value = 0;
		vector<int> path;
		vector<vector<int>> result;
		preorder(root,path_value,sum,path,result);
		return result;
	}
private:
	void preorder(TreeNode *node,int &path_value,int sum,
			vector<int> &path,vector<vector<int>> &result){
		if (!node)
		{
			return;
		}
		path_value += node->val;
		path.push_back(node->val);
		if (!node->left&&!node->right&&path_value==sum)
		{
			result.push_back(path);
		}
		preorder(node->left,path_value,sum,path,result);
		preorder(node->right,path_value,sum,path,result);
		path_value -= node->val;
		path.pop_back();
	}
};

//113.Path Sum II
int main(){
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &x;
	f.right = &y;
	Solution solve;
	vector<vector<int>> result = solve.pathSum(&a,22);
	for (int i=0;i<result.size();i++)
	{
		for (int j=0;j<result[i].size();j++)
		{
			printf("[%d] ",result[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}