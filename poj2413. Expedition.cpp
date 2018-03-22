#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>

bool cmp(const std::pair<int,int>&a,const std::pair<int,int>&b){
	return a.first>b.first; //从大到小
}

class Solution{
public:
	int get_minimum_stop(int L,int P,std::vector<std::pair<int,int>>&stop){
		//L为起点到终点距离，P为起点初始的汽油量，pair<加油点到终点距离，加油站汽油量>
		std::priority_queue<int> big_heap; //大顶堆
		int result = 0;//加油次数
		stop.push_back(std::make_pair(0,0));
		//先要排序
		std::sort(stop.begin(),stop.end(),cmp);
		for (int i=0;i<stop.size();i++)
		{
			int distance = L - stop[i].first; //加油站到下一个加油站的距离
			while (!big_heap.empty() && distance>P)//堆里非空，而且走不到下一个加油站了，就加油。
			{//加油
				P += big_heap.top(); //每次加的是最多的那个加油站里的油
				big_heap.pop();
				result++;
			}
			if (big_heap.empty() && distance>P)
			{
				return -1;
			}
			L = stop[i].first; //每次更新L
			//走路消耗油
			P -= distance;
			big_heap.push(stop[i].second);
		}
		return result;
	}
};

//poj2413. Expedition
int main(){	
	Solution solve;	
	std::vector<std::pair<int,int>> points;
	points.push_back(std::make_pair(4,4));
	points.push_back(std::make_pair(5,2));
	points.push_back(std::make_pair(11,5));
	points.push_back(std::make_pair(15,10));
	int result = solve.get_minimum_stop(25,10,points);
	printf("result:%d\n",result);
	system("pause");
	return 0;
}