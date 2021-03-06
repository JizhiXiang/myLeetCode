#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct BSTNode 
{
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x):val(x),left(NULL),right(NULL),count(0){}
};

void BST_insert(BSTNode *node,BSTNode *insert_node,int &count_small){
	if (insert_node->val <= node->val)
	{
		node->count++;
		if (node->left)
		{
			BST_insert(node->left,insert_node,count_small);
		}else{
			node->left = insert_node;
		}
	}else{
		//��
		count_small += (node->count+1);
		if (node->right)
		{
			BST_insert(node->right,insert_node,count_small);
		}else{
			node->right = insert_node;
		}
	}
}

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> result;
		vector<BSTNode*> node_vec;
		vector<int> count;
		for (int i=nums.size()-1;i>=0;i--)
		{
			node_vec.push_back(new BSTNode(nums[i]));
		}
		count.push_back(0);
		for (int i=1;i<node_vec.size();i++)
		{
			int count_small = 0;
			BST_insert(node_vec[0],node_vec[i],count_small);
			count.push_back(count_small);
		}
		for (int i=node_vec.size()-1;i>=0;i--)
		{
			delete node_vec[i];
			result.push_back(count[i]);
		}
		return result;
	}
};

//315. Count of Smaller Numbers After Self_��2
int main(){

	int test[] = {5,-7,9,1,3,5,-2,1};
	vector<int> nums;
	for (int i=0;i<8;i++)
	{
		nums.push_back(test[i]);
	}
	Solution solve;
	vector<int> result = solve.countSmaller(nums);
	for (int i=0;i<result.size();i++)
	{
		printf("[%d]",result[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}