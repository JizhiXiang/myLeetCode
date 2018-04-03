#include "stdafx.h"
#include <stdlib.h>
#include<vector>

class Solution{
public: 
	std::vector<std::vector<int>> subsets(std::vector<int>&nums){
		std::vector<int> item;
		std::vector<std::vector<int>> result;
		result.push_back(item); //先加入[]
		generate(0,nums,item,result);
		return result;
	}
private:
	void generate(int i,std::vector<int>&nums,std::vector<int>&item,std::vector<std::vector<int>>&result){
		if (i==nums.size())
		{
			return;
		}
		item.push_back(nums[i]);
		result.push_back(item);
		generate(i+1,nums,item,result);
		item.pop_back(); //加或不加
		generate(i+1,nums,item,result);
	}
};


//求子集（方法1）：回溯法
int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
//	nums.push_back(4);

	std::vector<std::vector<int>> result;	

	Solution solve;
	result = solve.subsets(nums);
	for (int i=0;i<result.size();i++)
	{
		//特殊处理
		if (result[i].size()==0)
		{
			printf("[]");
		}
		for (int j=0;j<result[i].size();j++)
		{
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}