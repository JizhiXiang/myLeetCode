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
		if (node->left)//×ó×ÓÊ÷²»¿Õ
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

void change_int_to_string(int val,string &str_val){
	string tmp;
	while (val)
	{
		tmp += val%10+'0';
		val = val/10;
	}
	for (int i=tmp.size()-1;i>=0;i--)
	{
		str_val += tmp[i];
	}
	str_val += '#';
}

void BST_preorder(TreeNode *root,string &data){
	string str_val;
	if (!root)
	{
		return;
	}
	change_int_to_string(root->val,str_val);
	data += str_val;
	BST_preorder(root->left,data);
	BST_preorder(root->right,data);
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

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string data;
		BST_preorder(root,data);
		return data;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.length()==0)
		{
			return NULL;
		}
		vector<TreeNode*> node_vec;
		int val = 0;
		for (int i=0;i<data.length();i++)
		{
			if (data[i]=='#')
			{
				node_vec.push_back(new TreeNode(val));
				val = 0;
			}else {
				val = 10*val + data[i]-'0';
			}
		}
		for (int i=1;i<node_vec.size();i++)
		{
			BST_insert(node_vec[0],node_vec[i]);
		}
		return node_vec[0];
	}
};

//449. Serialize and Deserialize BST
int main(){

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

	Codec solve;
	string data = solve.serialize(&a);
	printf("%s\n",data.c_str());
	TreeNode *root = solve.deserialize(data);
	preorder_print(root,0);
	system("pause");
	return 0;
}