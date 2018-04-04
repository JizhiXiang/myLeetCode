#include "stdafx.h"
#include <stdlib.h>
#include<string>
#include <vector>

class Solution{
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result;
		generate("",n,n,result);
		return result;
	}
private:
	void generate(std::string item,int left_leave,int right_leave,std::vector<std::string> &result){
		if (left_leave==0 && right_leave==0)
		{
			result.push_back(item);
			return;
		}
		if (left_leave>0)
		{
			generate(item+"(",left_leave-1,right_leave,result);
		}
		if (left_leave<right_leave)//左边剩的比右边的少
		{
			generate(item+")",left_leave,right_leave-1,result);
		}
	}
};


//22.Generate Parentheses
int main(){
	std::vector<std::string> result;
	Solution solve;
	result = solve.generateParenthesis(3);
	for (int i=0;i<result.size();i++)
	{
		printf("'%s'\n",result[i].c_str());
	}
	system("pause");
	return 0;
}