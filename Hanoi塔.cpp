#include "stdafx.h"
#include <stdlib.h>

//Hanoi��
static int m = 0;//����ƶ�����
void move(char a,char b,int disks)
{
	printf("��%d���ƶ�����%d�����Ӵ�%c�Ƶ�%c��\n",++m,disks,a,b);
}


void Hanoi(char &A,char &C,char &B,int n)
{//��A�ŵ�C�ϣ�����BΪ������

	if (n==1)//ֻ��һ�����ӣ�ֱ���ƶ�
	{
		move(A,C,1);
	}
	else{
		//����
		Hanoi(A,B,C,n-1);//�Ȱ�n-1���Ƶ�B
		move(A,C,n);//�ٰ����һ��(��n��)�ŵ�C
		Hanoi(B,C,A,n-1);
	}
}


int main(){	
	char A='A',B='B',C='C';
	int n;
	printf("����n��");
	scanf("%d",&n);
	Hanoi(A,C,B,n);
	system("pause");
	return 0;
}