#include "stdafx.h"
#include <stdlib.h>
#include <queue>

int main(int argc, _TCHAR* argv[])
{
	std::priority_queue<int> big_heap;
	/*小顶堆：std::priority_queue<int,std::vector<int>,std::greater<int>> small_heap;
	大顶堆：std::priority_queue<int,std::vector<int>,std::less<int>> big_heap;
	*/
	if (big_heap.empty())
	{
		printf("Empty!\n");
	}
	int test[]={6,7,1,4,99,10,33};
	for (int i=0;i<7;i++)
	{//装入
		big_heap.push(test[i]);
	}
	printf("%d ",big_heap.top());
	big_heap.push(1000);
	printf("%d ",big_heap.top());
	for (int i=0;i<3;i++)
	{//pop() 3个
		big_heap.pop();
	}
	printf("%d ",big_heap.top());
	printf("%d ",big_heap.size());

	system("pause");
	return 0;
}

