#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		//��ȷ�������ȶ�i���ٶ�begin
        int char_map[128] = {0};		
		string word = "";
		int result = 0;
		int begin = 0;
		for (int i = 0;i<s.length();i++)
		{	
			//i�����ƶ�
			char_map[s[i]]++;
			if (char_map[s[i]]==1)//word��û�г���
			{
				word += s[i];								
				if (result<word.length())
				{
					result = word.length();
				}
			}else {
				while (begin<i && char_map[s[i]]>1)
				{
					char_map[s[begin]]--;
					begin++;
				}
				word = "";
				for (int j=begin;j<=i;j++)
				{
					word += s[j];
				}
			}
		}
		return result;
    }
};
//3. Longest Substring Without Repeating Characters
int main(){	
	Solution solve;
	int x = solve.lengthOfLongestSubstring("abcbadab");
	printf("%d\n",x);
	system("pause");
	return 0;
}