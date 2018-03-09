#include "stdafx.h"
#include <stdlib.h>

//Hanoi塔
static int m = 0;//标记移动次数
void move(char a,char b,int disks)
{
	printf("第%d次移动：将%d号盘子从%c移到%c上\n",++m,disks,a,b);
}


void Hanoi(char &A,char &C,char &B,int n)
{//把A放到C上，其中B为辅助盘

	if (n==1)//只有一个盘子，直接移动
	{
		move(A,C,1);
	}
	else{
		//否则
		Hanoi(A,B,C,n-1);//先把n-1个移到B
		move(A,C,n);//再把最后一个(第n号)放到C
		Hanoi(B,C,A,n-1);
	}
}


int main(){	
	char A='A',B='B',C='C';
	int n;
	printf("输入n：");
	scanf("%d",&n);
	Hanoi(A,C,B,n);
	system("pause");
	return 0;
}