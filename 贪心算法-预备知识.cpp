#include "stdafx.h"
#include <stdlib.h>

int main(){	
	int const RMB[] ={100,50,20,10,5,2,1};
	int num=7;
	int x = 628;
	int count=0; //�����˶����ֽ��
	int use=0; //һ��ѭ���е�ֽ����
	for (int i=0;i<num;i++)
	{
		use = x/RMB[i];
		x = x - use*RMB[i];
		printf("�Ѿ�����%dԪ��%d�ţ���ʣ%dԪ\n",RMB[i],use,x);
		count += use;
	}
	printf("һ������%d��ֽ��\n",count);
	system("pause");
	return 0;
}