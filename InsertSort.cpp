#include "stdafx.h"
#include <stdlib.h>

//InsertSort
void InsertSort(int A[],int n)
{
	//��ǰ����ʼ���򣬵���
	for (int j=1;j<n;j++)
	{
		int x = A[j]; //�ȸ�ֵ������Ҫ��
		int i = j-1; //��ǰһ��
		while(i>=0&&x<A[i]) //x��ǰ��Ļ�С
		{
			A[i+1] = A[i];
			i--;
		}
		//�ٰ�x�ŵ����ʵ�λ��
		A[i+1] = x; //+1����Ϊǰ��������1
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