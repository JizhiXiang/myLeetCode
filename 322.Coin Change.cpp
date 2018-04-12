#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int coinChange(std::vector<int> &coins,int amount){
		//dp[i] 表示第i元时的最优解（最少张数）
		std::vector<int> dp(amount+1,-1);
		dp[0] = 0;
		for (int i=1;i<=amount;i++)
		{			
			for (int j=0;j<coins.size();j++)
			{				
				if (i-coins[j]>=0 && dp[i-coins[j]]!=-1)
				{
					if (dp[i]==-1 || dp[i]>dp[i-coins[j]]+1)
					{
						dp[i] = dp[i-coins[j]]+1;
					}
				}
			}
		}
		return dp[amount];
	}
};

//322.Coin Change
int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(10);
	solve.coinChange(nums,14);
	for (int i=1;i<=14;i++)
	{
		printf("dp[%d]=%d \n",i,solve.coinChange(nums,i));
	}
	system("pause");
	return 0;
}