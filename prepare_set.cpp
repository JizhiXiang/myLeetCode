#include "stdafx.h"
#include <stdlib.h>
#include <set>
#include <iostream>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	std::set<int> test_set; //使用STL的set.准备工作
	const int A_LEN = 7;
	const int B_LEN = 8;

	int a[A_LEN] = {5,1,4,8,10,1,3};
	int b[B_LEN] = {2,7,6,3,1,6,0,1};

	for (int i=0;i<A_LEN;i++)
	{
		test_set.insert(a[i]);
	}
	printf("%d ",test_set.find(b[3]));
	for (int i=0;i<B_LEN;i++)
	{
		if (test_set.find(b[i]) != test_set.end())
		{
			printf("b[%d]=%d in array A.\n",i,b[i]);
		}
	}	
	printf("%d ",test_set.find(b[3]));
	printf("%d ",test_set.find(2));
	printf("%d ",test_set.end());
	system("pause");	
	return 0;
}
