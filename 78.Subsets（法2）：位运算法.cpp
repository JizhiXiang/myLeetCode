#include "stdafx.h"
#include <stdlib.h>
#include<vector>

class Solution{
public: 
	std::vector<std::vector<int>> subsets(std::vector<int>&nums){		
		std::vector<std::vector<int>> result;
		int all_sets = 1<<nums.size();//总的个数
		for (int i=0;i<all_sets;i++)
		{
			std::vector<int> item;
			for (int j=0;j<nums.size();j++)
			{
				if (i&(1<<j))//如果真
				{
					item.push_back(nums[j]);
				}
			}
			result.push_back(item);
		}
		return result;
	}
};


//78.Subsets（法2）：位运算法
int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

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