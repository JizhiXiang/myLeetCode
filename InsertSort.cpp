#include "stdafx.h"
#include <stdlib.h>

//InsertSort
void InsertSort(int A[],int n)
{
	//从前往后开始排序，递增
	for (int j=1;j<n;j++)
	{
		int x = A[j]; //先赋值，后面要用
		int i = j-1; //往前一个
		while(i>=0&&x<A[i]) //x比前面的还小
		{
			A[i+1] = A[i];
			i--;
		}
		//再把x放到合适的位置
		A[i+1] = x; //+1是因为前面最后减了1
	}
}

int main(){	
	int A[]={ 12, 15, 9, 20, 6, 31, 24};
	InsertSort(A,7);
	for(int i=0;i<7;i++)
	{
		printf("%d ",A[i]);
	}
	system("pause");
	return 0;
}