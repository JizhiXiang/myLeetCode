#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <vector>

class Solution {
public:
	std::string removeKdigits(std::string num, int k) {
		std::vector<int> S; //充当栈的作用
		std::string result = "";
		int num_a;
		for (int i=0;i<num.length();i++)
		{
			num_a = num[i] - '0';
			while (k>0 && S.size()!=0 && num_a<S[S.size()-1])   //手动找出栈顶。后面的比前面小，删除前面那个（栈里）
			{
				S.pop_back();
				k--;
			}
			//怎样才能往栈里加入元素
			if (S.size()!=0 || num_a!=0)//不能加的情况：栈为空&&num_a为0
			{
				S.push_back(num_a);
			}
		}
		//一直递增的情况
		while (S.size()!=0 && k>0)
		{
			S.pop_back();
			k--;
		}
		for (int i=0;i<S.size();i++)
		{
			result.append(1,S[i]+'0');
		}
		if (result == "")
		{
			result = "0";
		}
		return result;
	}
};

//402. Remove K Digits
int main(){	
	Solution solve;
	std::string num = "10";//"1432219";
	int k = 1;
	std::string result = solve.removeKdigits(num,k);
	printf("结果为%s\n",result.c_str());
	system("pause");
	return 0;
}