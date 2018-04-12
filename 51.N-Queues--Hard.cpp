#include "stdafx.h"
#include <stdlib.h>
#include<string>
#include <vector>

class Solution{
public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<std::string> location;
		std::vector<std::vector<std::string>> result;
		std::vector<std::vector<int>> mark;
		for (int i=0;i<n;i++)
		{
			mark.push_back((std::vector<int>()));
			for (int j=0;j<n;j++)
			{
				mark[i].push_back(0);
			}
			location.push_back("");
			location[i].append(n,'.');
		}
		generate(0,n,location,result,mark);
		return result;
	}
private:
	void put_down_the_queue(int x,int y,std::vector<std::vector<int>>&mark){
		const static int dx[]={-1,-1,-1,0,0,1,1,1};//方向数组
		const static int dy[]={-1,0,1,-1,1,-1,0,1};
		mark[x][y] = 1;
		int new_x,new_y;
		for (int i=1;i<mark.size();i++)//各个方向走N-1步
		{
			for (int j=0;j<8;j++)
			{
				new_x = x + dx[j]*i;
				new_y = y + dy[j]*i;
				if (new_x>=0&&new_x<mark.size()&&new_y>=0&&new_y<mark.size())
				{
					mark[new_x][new_y] = 1;
				}
			}
		}
	}
	void generate(int k,int n,std::vector<std::string>&location,
		std::vector<std::vector<std::string>>&result,std::vector<std::vector<int>>&mark){
			//正在放第k行皇后，n*n矩阵
			if (k==n)
			{
				result.push_back(location);
				return;
			}
			for (int i=0;i<n;i++)//n列
			{
				if (mark[k][i]==0)
				{
					std::vector<std::vector<int>> tmp_mark = mark;
					location[k][i] = 'Q';
					put_down_the_queue(k,i,mark);//放皇后					
					generate(k+1,n,location,result,mark);
					//回溯
					mark = tmp_mark;
					location[k][i] = '.';
				}
			}
			
	}
};


//51.N-Queens_Hard
int main(){
	std::vector<std::vector<std::string>> result;
	Solution solve;
	result = solve.solveNQueens(4);
	for (int i=0;i<result.size();i++)
	{
		printf("i = %d\n",i);
		for (int j=0;j<result[i].size();j++)
		{
			printf("%s\n",result[i][j].c_str());
		}
		printf("\n");
	}
	system("pause");
	return 0;
}