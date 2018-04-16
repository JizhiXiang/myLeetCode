#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};


//邻接表构造图
int main(){
	const int MAX_N = 5;
	int Graph[MAX_N][MAX_N] = {0};
	Graph[0][4] = 1;
	Graph[0][2] = 1;
	Graph[1][0] = 1;
	Graph[1][2] = 1;
	Graph[2][3] = 1;
	Graph[3][4] = 1;
	Graph[4][3] = 1;
	printf("Graph:\n");
	for (int i=0;i<MAX_N;i++)
	{
		for (int j=0;j<MAX_N;j++)
		{
			printf("%d ",Graph[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}