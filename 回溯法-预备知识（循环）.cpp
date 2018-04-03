#include "stdafx.h"
#include <stdlib.h>
#include<vector>

//回溯法-预备知识（循环）
int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);

	std::vector<int> item;
	std::vector<std::vector<int>> result;

	for (int i=0;i<nums.size();i++)
	{
		item.push_back(nums[i]);
		result.push_back(item);
	}

	for (int i=0;i<result.size();i++)
	{
		for (int j=0;j<result[i].size();j++)
		{
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}