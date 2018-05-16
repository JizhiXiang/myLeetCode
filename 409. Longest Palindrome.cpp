#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int char_map[128] = {0};
		int max_length = 0;
		int flag = 0;
		for (int i=0;i<s.size();i++)
		{
			char_map[s[i]]++;
		}
		for (int i=0;i<128;i++)
		{
			if (char_map[i]%2==0)
			{//Å¼Êý
				max_length += char_map[i];
			}else{
				max_length += (char_map[i]-1);
				flag = 1;
			}
		}
		return max_length+flag;
	}
};
//409. Longest Palindrome
int main(){
	string s = "abcccccddaa";
	Solution solve;
	printf("%d\n",solve.longestPalindrome(s));
	system("pause");
	return 0;
}