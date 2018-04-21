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
	bool canFinish(int numCourse,vector<pair<int,int>> &prerequisities){ //课程2指向课程1		
		vector<GraphNode*> graph; //邻接表
		vector<int> visit;  //-1表示未访问，0表示正在访问，1表示已经访问
		for (int i=0;i<numCourse;i++)
		{
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}
		//创建图，连接顶点
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
		visit[node->label] = 0; //-1表示未访问，0表示正在访问，1表示已经访问
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