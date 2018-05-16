#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;


int main(){
	//×Ö·û¹şÏ£
	int char_map[128] = {0};
	string str = "abcdefgaaxxyy";

	for (int i=0;i<str.length();i++)
	{
		char_map[str[i]]++;
	}
	for (int i=0;i<128;i++)
	{
		if (char_map[i]>0)
		{
			printf("[%c][%d]: %d\n",i,i,char_map[i]);
		}
	}

	//¹şÏ£±íÅÅĞòÕûÊı
	int random[10] = {999,1,444,7,20,9,1,3,7,7};
	int hash_map[1000] = {0};
	for (int i=0;i<10;i++)
	{
		hash_map[random[i]]++;
	}
	for (int i=0;i<1000;i++)
	{
		for (int j=0;j<hash_map[i];j++)
		{
			printf("%d\n",i);
		}
	}
	system("pause");
	return 0;
}