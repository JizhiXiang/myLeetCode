#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
		if (dungeon.size()==0)
		{
			return 0;
		}		
		int row = dungeon.size();
		int column = dungeon[0].size();//列
		/*
		std::vector<std::vector<int>> dp;
		for (int i=0;i<row;i++)
		{//初始化dp
			dp.push_back(std::vector<int>());
			for (int j=0;j<column;j++)
			{
				dp[i].push_back(0);
			}
		}*/
		//也可以这样初始化dp
		std::vector<std::vector<int>> dp(dungeon.size(),std::vector<int>(dungeon[0].size(),0));
		dp[row-1][column-1] = std::max(1,1-dungeon[row-1][column-1]);//减去要加的血，最少为1
		for (int j=column-2;j>=0;j--)
		{//最后一行
			dp[row-1][j] = std::max(1,dp[row-1][j+1]-dungeon[row-1][j]);
		}
		for (int i=row-2;i>=0;i--)
		{//最后一列
			dp[i][column-1] = std::max(1,dp[i+1][column-1]-dungeon[i][column-1]);
		}
		for (int i=row-2;i>=0;i--)
		{
			for (int j=column-2;j>=0;j--)
			{
				int min_temp = std::min(dp[i][j+1],dp[i+1][j]);
				dp[i][j] = std::max(1,min_temp-dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};

//174. Dungeon Game
int main(){
	Solution solve;
	int test[][3]={{-2,-3,3},{-5,-10,1},{10,30,-5}};
	std::vector<std::vector<int>> dungeon;
	for (int i=0;i<3;i++)
	{
		dungeon.push_back(std::vector<int>());
		for (int j=0;j<3;j++)
		{
			dungeon[i].push_back(test[i][j]);
		}
	}
	printf("%d\n",solve.calculateMinimumHP(dungeon));
	system("pause");
	return 0;
}