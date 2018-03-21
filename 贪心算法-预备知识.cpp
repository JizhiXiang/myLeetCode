#include "stdafx.h"
#include <stdlib.h>

int main(){	
	int const RMB[] ={100,50,20,10,5,2,1};
	int num=7;
	int x = 628;
	int count=0; //共用了多个张纸币
	int use=0; //一次循环中的纸币数
	for (int i=0;i<num;i++)
	{
		use = x/RMB[i];
		x = x - use*RMB[i];
		printf("已经用了%d元的%d张，还剩%d元\n",RMB[i],use,x);
		count += use;
	}
	printf("一共用了%d张纸币\n",count);
	system("pause");
	return 0;
}