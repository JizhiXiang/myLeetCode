#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string,vector<string>> anagram;
		for (int i=0;i<strs.size();i++)
		{
			string str = strs[i];
			sort(str.begin(),str.end());
			if (anagram.find(str)==anagram.end())
			{//Ã»ÕÒµ½
				vector<string> item;
				anagram[str] = item;
			}			
			anagram[str].push_back(strs[i]);			
		}
		vector<vector<string>> result;
		map<string,vector<string>>::iterator it;
		for (it=anagram.begin();it!=anagram.end();it++)
		{
			result.push_back((*it).second);
		}
		return result;
	}
};
//49. Group Anagrams
int main(){	
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("bat");
	Solution solve;
	vector<vector<string>> result = solve.groupAnagrams(strs);
	for (int i=0;i<result.size();i++)
	{
		for (int j=0;j<result[i].size();j++)
		{
			printf("[%s]",result[i][j].c_str());
		}
		printf("\n");
	}
	system("pause");
	return 0;
}