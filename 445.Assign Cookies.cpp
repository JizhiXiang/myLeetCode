#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

class Solution{
public:
	int findContentChildren(std::vector<int>&g, std::vector<int> &s){
		std::sort(g.begin(),g.end()); //从小到大排序
		std::sort(s.begin(),s.end());
		int i=0,j=0;
		int num = 0;//孩子被满足的人数
		while(i<g.size()&&j<s.size()){
			if (g[i]<=s[j])
			{
				i++;
				num++;
			}
			j++; //j反正都要一直往后加的
		}
		return num;
	}
};

//445. Assign Cookies 
int main(){	
	Solution solve;
	int gg[] = {5,10,2,9,15,9};	int g_n=6;
	int ss[] = {6,1,20,3,8}; int s_n=5;
	std::vector<int> g;
	std::vector<int> s;
	for (int i=0;i<g_n;i++)
	{
		g.push_back(gg[i]);
	}
	for (int i=0;i<s_n;i++)
	{
		s.push_back(ss[i]);
	}
	int num = solve.findContentChildren(g,s);
	printf("有%d个小孩被满足\n",num);
	system("pause");
	return 0;
}