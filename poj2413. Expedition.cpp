#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>

bool cmp(const std::pair<int,int>&a,const std::pair<int,int>&b){
	return a.first>b.first; //�Ӵ�С
}

class Solution{
public:
	int get_minimum_stop(int L,int P,std::vector<std::pair<int,int>>&stop){
		//LΪ��㵽�յ���룬PΪ����ʼ����������pair<���͵㵽�յ���룬����վ������>
		std::priority_queue<int> big_heap; //�󶥶�
		int result = 0;//���ʹ���
		stop.push_back(std::make_pair(0,0));
		//��Ҫ����
		std::sort(stop.begin(),stop.end(),cmp);
		for (int i=0;i<stop.size();i++)
		{
			int distance = L - stop[i].first; //����վ����һ������վ�ľ���
			while (!big_heap.empty() && distance>P)//����ǿգ������߲�����һ������վ�ˣ��ͼ��͡�
			{//����
				P += big_heap.top(); //ÿ�μӵ��������Ǹ�����վ�����
				big_heap.pop();
				result++;
			}
			if (big_heap.empty() && distance>P)
			{
				return -1;
			}
			L = stop[i].first; //ÿ�θ���L
			//��·������
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