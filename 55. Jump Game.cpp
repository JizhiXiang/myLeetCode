#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	bool canJump(std::vector<int>& nums) {
		std::vector<int> index;
		for (int i=0;i<nums.size();i++)
		{
			index.push_back(nums[i]+i); //能跳到第index[i]的位置
		}
		int jump=0; //从0开始遍历index数组
		int max_index = index[0]; //初始化
		while (jump<index.size()&&jump<=max_index) //jump到index末尾 或者 jump>max_index就跳出循环
		{
			if (max_index<index[jump]) //要取大的
			{
				max_index = index[jump];
			}
			jump++; //后移
		}
		if (jump==index.size())
		{
			return true;
		}
		else{
			return false;
		}
	}
};

//55. Jump Game
int main(){	
	Solution solve;	
	int A[] = {3,2,1,0,4};//{2,3,1,1,4};
	int n = sizeof(A)/sizeof(A[0]);
	std::vector<int> nums;
	for (int i=0;i<n;i++)
	{
		nums.push_back(A[i]);
	}
	int result = solve.canJump(nums);
	printf("result:%d\n",result);
	system("pause");
	return 0;
}