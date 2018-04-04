#include "stdafx.h"
#include <stdlib.h>
#include<vector>
#include <set>
#include <algorithm>

class Solution{
public: 
	std::vector<std::vector<int>> subsetsWithDup(std::vector<int>&nums){
		std::vector<std::vector<int>> result;
		std::set<std::vector<int>> res_set;
		std::vector<int> item;
		result.push_back(item);
		std::sort(nums.begin(),nums.end());
		generate(0,nums,result,item,res_set);
		return result; //res_set�������ų���ͬ�Ӽ��ģ������ػ���Ҫresult(ʵ������������һ��)
	}
private:
	void generate(int i,std::vector<int>&nums,
		std::vector<std::vector<int>>&result,std::vector<int>&item,std::set<std::vector<int>>&res_set){
			if (i==nums.size())
			{
				return;
			}
			item.push_back(nums[i]);
			if (res_set.find(item)==res_set.end())//�Ҳ���
			{
				result.push_back(item);
				res_set.insert(item);
			}
			generate(i+1,nums,result,item,res_set);//�ݹ����
			//�ٵ������ٵݹ�
			item.pop_back();
			generate(i+1,nums,result,item,res_set);
	}
};


//90.SubsetsII
int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	std::vector<std::vector<int>> result;	

	Solution solve;
	result = solve.subsetsWithDup(nums);
	for (int i=0;i<result.size();i++)
	{
		//���⴦��
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