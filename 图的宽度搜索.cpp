#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct GraphNode{
	int label;
	vector<GraphNode* > neighbors;
	GraphNode(int x):label(x){ }
};

#include <queue>
void BFS_graph(GraphNode *node,int visit[]){
	queue<GraphNode*> Q;
	Q.push(node);
	while(!Q.empty()){
		GraphNode *node = Q.front();
		printf("%d ",node->label);
		visit[node->label] = 1;
		Q.pop();
		for (int i=0;i<node->neighbors.size();i++)
		{
			if (visit[node->neighbors[i]->label]==0)
			{
				Q.push(node->neighbors[i]);
			}
		}
	}
}

//图的宽度搜索
int main(){
	const int MAX_N = 5;
	GraphNode *Graph[MAX_N];
	for (int i=0;i<MAX_N;i++)
	{
		Graph[i] = new GraphNode(i);
	}
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);
	int visit[MAX_N] = {0};
	for (int i=0;i<MAX_N;i++)
	{
		if (visit[i]==0)
		{
			printf("从label[%d]开始遍历：",i);
			BFS_graph(Graph[i],visit);
			printf("\n");
		}
	}
	for (int i=0;i<MAX_N;i++)
	{
		delete Graph[i];
	}
	system("pause");
	return 0;
}