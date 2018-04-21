#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

struct GraphNode{
	int label;
	vector<GraphNode* > neighbors;
	GraphNode(int x):label(x){ }
};

class Solution{
public:
	bool canFinish(int numCourse,vector<pair<int,int>> &prerequisities){ //�γ�2ָ��γ�1		
		vector<GraphNode*> graph;
		vector<int> degree;  //�������
		//����ͼ�ڵ�
		for (int i=0;i<numCourse;i++)
		{
			graph.push_back(new GraphNode(i));
			degree.push_back(0);
		}
		//���ӣ���ʼ�����
		for (int i=0;i<prerequisities.size();i++)
		{
			GraphNode* begin = graph[prerequisities[i].second];
			GraphNode* end = graph[prerequisities[i].first];
			begin->neighbors.push_back(end);
			degree[end->label]++; //��ȼ�һ
		}
		//�ѽڵ�Ž�����Q��
		queue<GraphNode*> Q;
		for (int i=0;i<numCourse;i++)
		{
			if (degree[i]==0)
			{
				Q.push(graph[i]);
			}
		}
		while (!Q.empty())
		{
			GraphNode* node = Q.front();
			Q.pop();
			for (int i=0;i<node->neighbors.size();i++)
			{
				degree[node->neighbors[i]->label]--;
				if (degree[node->neighbors[i]->label]==0)
				{
					Q.push(node->neighbors[i]);
				}
			}
		}
		for (int i=0;i<numCourse;i++)
		{
			delete graph[i];
		}
		for (int i=0;i<numCourse;i++)
		{
			if (degree[i]!=0)
			{
				return false;
			}			
		}
		return true;
	}
};

//207.Course Schedule
int main(){
	vector<pair<int,int>> prerequisites;
	prerequisites.push_back(make_pair(1,0));
	prerequisites.push_back(make_pair(2,0));
	prerequisites.push_back(make_pair(3,1));
	prerequisites.push_back(make_pair(3,2));
	Solution solve;
	printf("%d\n",solve.canFinish(4,prerequisites));
	system("pause");
	return 0;
}