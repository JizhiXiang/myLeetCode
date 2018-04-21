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
	TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){//树根节点为root，待查找的为p和q
		vector<TreeNode*> path;
		vector<TreeNode*> p_result;
		vector<TreeNode*> q_result;		
		int finish = 0;
		path.clear();
		preoder(root,p,path,p_result,finish);
		path.clear();
		finish = 0;
		preoder(root,q,path,q_result,finish);
		int len_short=0; //较短的长度
		if (p_result.size()<q_result.size())
		{
			len_short = p_result.size();
		}
		else{
			len_short = q_result.size();
		}
		TreeNode* result = 0;
		for (int i=0;i<len_short;i++)
		{
			if (p_result[i]==q_result[i])
			{
				result = p_result[i];
			}
		}
		return result;
	}
private:
	void preoder(TreeNode *node,  //树的根节点
		TreeNode *search, //待搜索节点
		vector<TreeNode*> &path, //遍历节点路径栈
		vector<TreeNode*> &result,//结果
		int &finish){ //是否找到
			if (!node||finish==1)
			{
				return ;
			}			
			path.push_back(node);
			if (node==search)
			{
				finish = 1;
				result = path;
			}
			preoder(node->left,search,path,result,finish);
			preoder(node->right,search,path,result,finish);
			path.pop_back();
	}
};

//236.Lowest Common Ancestor for a Binary Tree
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
	TreeNode* result = solve.lowestCommonAncestor(&a,&d,&i);
	printf("%d \n",result->val);
	system("pause");
	return 0;
}