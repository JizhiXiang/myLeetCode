#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	int minimumTotal(std::vector<std::vector<int>>& triangle) {
		if (triangle.size()==0)
		{
			return 0;
		}
		std::vector<std::vector<int>> dp;
		//初始化dp
		int row = triangle.size();
		for (int i=0;i<triangle.size();i++)
		{
			dp.push_back(std::vector<int>());
			for (int j=0;j<triangle[i].size();j++)
			{
				dp[i].push_back(0);
			}
		}
		//最后一行
		for (int j=0;j<triangle[row-1].size();j++)
		{
			dp[row-1][j] = triangle[row-1][j];
		}
		//递推公式
		for (int i=row-2;i>=0;i--)
		{
			for (int j=0;j<triangle[i].size();j++)
			{
				dp[i][j] = std::min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
			}
		}
		return dp[0][0];
	}
};

//120. Triangle
int main(){
	Solution solve;
	std::vector<std::vector<int>> triangle;
	int test[][10] = {{2},{3,4},{6,5,7},{4,1,8,3}};
	for (int i=0;i<4;i++)
	{
		triangle.push_back(std::vector<int>()); //放空的
		for (int j=0;j<i+1;j++)
		{
			triangle[i].push_back(test[i][j]);
		}
	}
	printf("%d\n",solve.minimumTotal(triangle));
	system("pause");
	return 0;
}