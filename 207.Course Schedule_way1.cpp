#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct GraphNode{
	int label;
	vector<GraphNode* > neighbors;
	GraphNode(int x):label(x){ }
};

class Solution{
public:
	bool canFinish(int numCourse,vector<pair<int,int>> &prerequisities){ //�γ�2ָ��γ�1		
		vector<GraphNode*> graph; //�ڽӱ�
		vector<int> visit;  //-1��ʾδ���ʣ�0��ʾ���ڷ��ʣ�1��ʾ�Ѿ�����
		for (int i=0;i<numCourse;i++)
		{
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}
		//����ͼ�����Ӷ���
		for (int i=0;i<prerequisities.size();i++)
		{
			GraphNode *begin = graph[prerequisities[i].second];
			GraphNode *end = graph[prerequisities[i].first];
			begin->neighbors.push_back(end);
		}
		for (int i=0;i<graph.size();i++)
		{
			if (visit[i]==-1&&!DFS_graph(graph[i],visit))
			{
				return false;
			}
		}
		for (int i=0;i<graph.size();i++)
		{
			delete graph[i];
		}
		return true;
	}
private:
	bool DFS_graph(GraphNode *node,vector<int> visit){
		visit[node->label] = 0; //-1��ʾδ���ʣ�0��ʾ���ڷ��ʣ�1��ʾ�Ѿ�����
		for(int i=0;i<node->neighbors.size();i++)
		{
			if (visit[node->neighbors[i]->label]==-1)
			{
				if (DFS_graph(node->neighbors[i],visit)==0)
				{
					return false;
				}
			}
			else if (visit[node->neighbors[i]->label]==0)
			{
				return false;
			}
		}
		visit[node->label] = 1;
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