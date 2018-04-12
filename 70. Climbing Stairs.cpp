#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int climbStairs(int n) {
		std::vector<int> dp(n+3,0);
		dp[1]=1;
		dp[2]=2;
		for (int i=3;i<=n;i++)
		{
			dp[i] = dp[i-1]+dp[i-2];
		}
		return dp[n];
	}
};

//70. Climbing Stairs
int main(){
	Solution solve;
	printf("%d\n",solve.climbStairs(3));
	system("pause");
	return 0;
}