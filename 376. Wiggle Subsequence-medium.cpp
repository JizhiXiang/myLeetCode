#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>

class Solution{
public:
	int wiggleMaxLength(std::vector<int>& nums){		
		if (nums.size()<2)
		{
			return nums.size();
		}
		//用状态机来考虑
		int const START = 0;
		int const UP = 1;
		int const DOWN = 2;
		int i=1;//从第2个开始
		int status = START;
		int result = 1;//返回结果
		while (i<nums.size())
		{
			switch (status)
			{
			case START:
				if (nums[i]>nums[i-1]){ //后面的比前面的大，所以UP
					status = UP;
					result++;
				}
				if (nums[i]<nums[i-1])
				{
					status = DOWN;
					result++;
				}
				break;			
			case UP:
				if (nums[i]<nums[i-1])
				{
					status = DOWN;
					result++;
				}
				//其余的情况：相等，变大。状态都不变。
				break;
			case DOWN:
				if (nums[i]>nums[i-1]){ 
					status = UP;
					result++;
				}
			}
			i++;//每次都要往后面走一步
		}
		return result;
	}
};

//376. Wiggle Subsequence
int main(){	
	Solution solve;
	//int nums_a[]={1,7,4,9,2,5};
	int nums_a[]= {1,17,5,10,13,15,10,5,16,8};
	int n=sizeof(nums_a)/sizeof(nums_a[0]);	
	std::vector<int> nums;	
	for (int i=0;i<n;i++)
	{
		nums.push_back(nums_a[i]);
	}		
	int result = solve.wiggleMaxLength(nums);
	printf("结果为%d\n",result);
	system("pause");
	return 0;
}