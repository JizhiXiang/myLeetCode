#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int,int>&a,const std::pair<int,int>&b){
	return a.first<b.first;
}

class Solution{
public:
	int findMinArrowShots(std::vector<std::pair<int,int>>& points){
		if (points.size()==0)
		{
			return 0;
		}
		std::sort(points.begin(),points.end(),cmp);
		int result = 1;
		int shoot_begin = points[0].first;
		int shoot_end = points[0].second;
		for (int i=1;i<points.size();i++)
		{
			if (points[i].first<=shoot_end) //前面那个和这个有交集
			{
				shoot_begin = points[i].first;
				if (shoot_end>=points[i].second)//有交集有两种情况
				{
					shoot_end = points[i].second;
				}
			}else{
				//没有交集
				result++;
				shoot_begin = points[i].first;
				shoot_end = points[i].second;
			}			
		}
		return result;
	}
};

//452. Minimum Number of Arrows to Burst Balloons
int main(){	
	Solution solve;	
	std::vector<std::pair<int,int>> points;
	points.push_back(std::make_pair(10,16));
	points.push_back(std::make_pair(2,8));
	points.push_back(std::make_pair(1,6));
	points.push_back(std::make_pair(7,12));
	int result = solve.findMinArrowShots(points);
	printf("result:%d\n",result);
	system("pause");
	return 0;
}