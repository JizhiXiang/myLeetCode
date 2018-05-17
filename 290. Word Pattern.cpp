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
		int pos = 0; //pattern 的位置
		str += ' ';
		string tmp;		
		for(int i=0;i<str.size();i++)
		{
			if (str[i]==' ')
			{//分得一个词
				if (pos == pattern.length())
				{//到最后一个了(超出了)
					return false;
				}
				if (word_map.find(tmp)==word_map.end())
				{//没找到
					if (used[pattern[pos]])
					{//被使用过
						return false;
					}
					word_map[tmp] = pattern[pos];
					used[pattern[pos]] = 1;
				}else{
					//出现过
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
		{//pattern 多了
			return false;
		}
		return true;
	}
};
//290. Word Pattern
/*一定要记得，不然错误都很难找
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