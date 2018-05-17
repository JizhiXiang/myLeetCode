#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {		
		map<string, char> word_map;
		int used[128]={0};
		int pos = 0; //pattern ��λ��
		str += ' ';
		string tmp;		
		for(int i=0;i<str.size();i++)
		{
			if (str[i]==' ')
			{//�ֵ�һ����
				if (pos == pattern.length())
				{//�����һ����(������)
					return false;
				}
				if (word_map.find(tmp)==word_map.end())
				{//û�ҵ�
					if (used[pattern[pos]])
					{//��ʹ�ù�
						return false;
					}
					word_map[tmp] = pattern[pos];
					used[pattern[pos]] = 1;
				}else{
					//���ֹ�
					if (word_map[tmp]!=pattern[pos])
					{
						return false;
					}
				}
				pos++ ;
				tmp = "";
			}else{
				tmp += str[i];
			}
		}
		if (pos!=pattern.length())
		{//pattern ����
			return false;
		}
		return true;
	}
};
//290. Word Pattern
/*һ��Ҫ�ǵã���Ȼ���󶼺�����
#include <map>
#include <string>
*/
int main(){	
	string pattern = "abbc";
	string str = "cat dog dog cat";
	Solution solve;	
	printf("%d\n",solve.wordPattern(pattern,str));
	system("pause");
	return 0;
}