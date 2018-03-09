#include "stdafx.h"
#include <stdlib.h>

//MergeSort二路归并,tmp还是比较重要的
void Merge(int *A,int low,int mid,int high,int *tmp)
{//将[low,mid],(mid,high]两端合并起来
	int i = low;
	int j = mid+1;
	int k = 0;//用来给tmp计数的

	while(i<=mid&&j<=high)
	{
		if (A[i]<=A[j])
		{//小的放在tmp中
			tmp[k++] = A[i++];
		} 
		else
		{
			tmp[k++] = A[j++];
		}
	}
	//如果一方还有剩
	while(i<=mid)
	{
		tmp[k++] = A[i++];
	}
	while(j<=high)
	{
		tmp[k++] = A[j++];
	}
	for(int i=0;i<k;i++)//共有k个
	{
		A[low+i] = tmp[i];
	}
}

void MergeSort(int *A,int low,int high,int *tmp)
{
	if (low<high)
	{
		int mid = (low+high)/2;
		MergeSort(A,low,mid,tmp);
		MergeSort(A,mid+1,high,tmp);
		//再把左右两端连起来
		Merge(A,low,mid,high,tmp);
	}
}

int main(){	
	int A[]={2,23,34,43,45,6,7,8,5,4,56,78,80,211,222,444,111};
	int num = sizeof(A)/sizeof(A[0]);
	int *tmp = new int[num];
	MergeSort(A,0,num-1,tmp);
	for(int i=0;i<num;i++)
	{
		printf("%d ",A[i]);
	}
	delete []tmp;
	system("pause");
	return 0;
}