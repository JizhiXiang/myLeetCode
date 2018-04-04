#include "stdafx.h"
#include <stdlib.h>
#include<vector>
#include <set>
#include <algorithm>

class Solution{
public: 
	std::vector<std::vector<int>> combinationSum2(std::vector<int>&candidate,int target){
		std::vector<std::vector<int>> result;
		std::set<std::vector<int>> res_set;
		std::vector<int> item;		
		std::sort(candidate.begin(),candidate.end());
		generate(0,candidate,result,item,res_set,0,target);
		return result; //res_set是用来排除相同子集的，但返回还是要result(实际上两者内容一样)
	}
private:
	void generate(int i,std::vector<int>&nums,std::vector<std::vector<int>>&result,
		std::vector<int>&item,std::set<std::vector<int>>&res_set,int sum,int target){			
			if (i==nums.size()||sum>target)
			{
				return;
			}
			sum += nums[i];
			item.push_back(nums[i]);
			if (sum==target && res_set.find(item)==res_set.end())//等于target 而且里面没有
			{
				result.push_back(item);
				res_set.insert(item);
			}
			generate(i+1,nums,result,item,res_set,sum,target);//递归调用
			sum -= nums[i]; //弹出
			item.pop_back();
			generate(i+1,nums,result,item,res_set,sum,target);
	}
};


//40.Combination Sum II
int main(){
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);

	std::vector<std::vector<int>> result;	

	Solution solve;
	result = solve.combinationSum2(nums,8);
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