#include "stdafx.h"
#include <stdlib.h>
#include <vector>

void merge_two_vec(std::vector<int>&A,std::vector<int>&B,std::vector<int>&result){
	int i = 0;
	int j = 0;	
	while (i<A.size()&&j<B.size())
	{
		if (A[i]<B[j])
		{
			result.push_back(A[i]);
			i++;
		}
		else{
			result.push_back(B[j]);
			j++;
		}
	}
	for (;i<A.size();i++)
	{
		result.push_back(A[i]);
	}
	for (;j<B.size();j++)
	{
		result.push_back(B[j]);
	}
}

void merge_sort(std::vector<int> &vec){
	if (vec.size()==1)
	{
		return;
	}
	int mid = vec.size()/2;
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2;
	for (int i=0;i<mid;i++)
	{
		sub_vec1.push_back(vec[i]);
	}
	for (int j=mid;j<vec.size();j++)
	{
		sub_vec2.push_back(vec[j]);
	}
	merge_sort(sub_vec1);
	merge_sort(sub_vec2);
	vec.clear();
	merge_two_vec(sub_vec1,sub_vec2,vec);
}

//¹é²¢ÅÅÐò·¨
int main(){

	std::vector<int> vec;
	int test[] = {2,3,4,1,2,4,8,0,5,3,1};
	for (int i=0;i<11;i++)
	{
		vec.push_back(test[i]);
	}
	merge_sort(vec);
	for (int i=0;i<vec.size();i++)
	{
		printf("%d ",vec[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}