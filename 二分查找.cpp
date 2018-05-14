#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

//二分查找（递归）
bool binary_search(vector<int> &sort_array,int begin,int end,int target){
	if (begin>end)
	{
		return false;
	}
	int mid = (begin+end)/2;
	if (target == sort_array[mid])
	{
		return true;
	}else if (target<sort_array[mid]){
		binary_search(sort_array,begin,mid-1,target);
	}else{
		binary_search(sort_array,mid+1,end,target);
	}
}

//二分查找(循环法)
bool binary_search2(vector<int>&sort_array,int target){
	int begin = 0;
	int end = sort_array.size()-1;
	while(begin<=end){
		int mid = (begin+end)/2;
		if (target==sort_array[mid])
		{
			return true;
		}else if (target<sort_array[mid])
		{
			end = mid-1;
		}else if (target>sort_array[mid])
		{
			begin = mid+1;
		}
	}
	return false;
}

int main(){

	system("pause");
	return 0;
}