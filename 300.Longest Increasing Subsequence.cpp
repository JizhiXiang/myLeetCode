#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int lengthOfLIS(std::vector<int>& nums) {
		if (nums.size()==0)
		{
			return 0;
		}
		std::vector<int> dp(nums.size(),0);
		dp[0] = 1;
		int LIS = 1;
		for (int i=1;i<nums.size();i++)
		{
			dp[i]=1;
			for (int j=0;j<i;j++)
			{
				if (nums[i]>nums[j])
				{
					if (dp[i]< dp[j]+1)
					{
						dp[i] = dp[j]+1; //È¡×î´ó
					}
				}
			}
			if (LIS<=dp[i])
			{
				LIS = dp[i];
			}
		}
		return LIS;
	}
};

//300.Longest Increasing Subsequence
int main(){
	Solution solve;
	int test[]={1,3,2,3,1,4};
	std::vector<int> nums;
	for (int i=0;i<6;i++)
	{
		nums.push_back(test[i]);
	}
	printf("%d\n",solve.lengthOfLIS(nums));
	system("pause");
	return 0;
}