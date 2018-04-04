#include "stdafx.h"
#include <stdlib.h>
#include<string>
#include <vector>

void generate(std::string item,int n, std::vector<std::string> &result){
	if (item.size()==2*n)
	{
		result.push_back(item);
		return;
	}
	generate(item+"(",n,result);
	generate(item+")",n,result);
}

//22.Generate Parentheses
int main(){
	std::vector<std::string> result;
	generate("",2,result);
	for (int i=0;i<result.size();i++)
	{
		printf("'%s'\n",result[i].c_str());
	}
	system("pause");
	return 0;
}