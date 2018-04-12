#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int minPathSum(std::vector<std::vector<int>>& grid) {
		if (grid.size()==0)
		{
			return 0;
		}
		int row = grid.size();
		int column = grid[0].size();
		std::vector<std::vector<int>> dp;
		for (int i=0;i<grid.size();i++)
		{
			dp.push_back(std::vector<int>());
			for (int j=0;j<grid[i].size();j++)
			{
				dp[i].push_back(0);
			}
		}
		dp[0][0] = grid[0][0];
		for (int i=1;i<row;i++)
		{//第一列
			dp[i][0] = dp[i-1][0]+grid[i][0];
		}
		for (int j=1;j<column;j++)
		{//第一行
			dp[0][j] = dp[0][j-1] + grid[0][j];
		}
		for (int i=1;i<grid.size();i++)
		{
			for (int j=1;j<grid[i].size();j++)
			{
				dp[i][j] = std::min(dp[i-1][j],dp[i][j-1])+grid[i][j];
			}
		}
		return dp[row-1][column-1];
	}
};
//64.Minimum Path Sum
int main(){
	Solution solve;
	int test[][3]={{1,3,1},{1,5,1},{4,2,1}};
	std::vector<std::vector<int>> grid;
	for (int i=0;i<3;i++)
	{
		grid.push_back(std::vector<int>());
		for (int j=0;j<3;j++)
		{
			grid[i].push_back(test[i][j]);
		}
	}
	printf("%d\n",solve.minPathSum(grid));
	system("pause");
	return 0;
}