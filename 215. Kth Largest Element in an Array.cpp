#include "stdafx.h"
#include <stdlib.h>
#include <queue>
#include <vector>

//215. Kth Largest Element in an Array
class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::priority_queue<int,std::vector<int>,std::less<int>> big_heap;//大顶堆
		int n = nums.size();
		for(int i=0;i<n;i++)
		{
			big_heap.push(nums[i]);
		}
		while(--k)
		{//因为是第K大的那个
			big_heap.pop();
		}
		return big_heap.top();
	}
};

int main(){	
	std::vector<int> nums;
	int A[] = {3,2,1,5,6,4,9,7,8};
	int n = sizeof(A)/sizeof(A[0]);
	for(int i=0;i<n;i++)
	{
		nums.push_back(A[i]);
	}
	Solution solve;
	int reslut = solve.findKthLargest(nums,3);
	printf("为：%d\n",reslut);
	system("pause");
	return 0;
}