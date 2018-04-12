#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	std::vector<int> countSmaller(std::vector<int>& nums) {
		std::vector<std::pair<int,int>> vec;
		std::vector<int> count;
		for (int i=0;i<nums.size();i++)
		{
			vec.push_back(std::make_pair(nums[i],i));
			count.push_back(0);
		}
		merge_sort(vec,count);
		return count;
	}

private:
	void merge_two_vec(std::vector<std::pair<int,int>>&A,std::vector<std::pair<int,int>>&B,
				std::vector<std::pair<int,int>>&result,std::vector<int> &count){
		int i = 0;
		int j = 0;	
		while (i<A.size()&&j<B.size())
		{
			if (A[i].first<=B[j].first)
			{
				count[A[i].second] += j;
				result.push_back(A[i]);
				i++;
			}
			else{
				result.push_back(B[j]);
				j++;
			}
		}
		for (;i<A.size();i++)
		{
			count[A[i].second] += j;
			result.push_back(A[i]);
		}
		for (;j<B.size();j++)
		{
			result.push_back(B[j]);
		}
	}

	void merge_sort(std::vector<std::pair<int,int>> &vec,std::vector<int>&count){
		if (vec.size()==1)
		{
			return;
		}
		int mid = vec.size()/2;
		std::vector<std::pair<int,int>> sub_vec1;
		std::vector<std::pair<int,int>> sub_vec2;
		for (int i=0;i<mid;i++)
		{
			sub_vec1.push_back(vec[i]);
		}
		for (int j=mid;j<vec.size();j++)
		{
			sub_vec2.push_back(vec[j]);
		}
		merge_sort(sub_vec1,count);
		merge_sort(sub_vec2,count);
		vec.clear();
		merge_two_vec(sub_vec1,sub_vec2,vec,count);
	}
};

//315.Count of Smaller Numbers After Self
int main(){

	std::vector<int> nums;
	int test[] = {5,-7,9,1,3,5,-2,1};
	for (int i=0;i<8;i++)
	{
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);	
	for (int i=0;i<result.size();i++)
	{
		printf("%d ",result[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}