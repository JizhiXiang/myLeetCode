#include "stdafx.h"
#include <stdlib.h>
#include <queue>
#include <vector>

//215. Kth Largest Element in an Array
class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::priority_queue<int,std::vector<int>,std::greater<int>> small_heap;//小顶堆
		int n = nums.size();
		//先把前面k个放进小顶堆
		int i;
		for(i=0;i<k;i++)
		{
			small_heap.push(nums[i]);
		}
		//从下一个开始,实际上i已经自动+1了
		while(i<n){
			if(nums[i]>small_heap.top()) //新加的比堆里最小的要大，就替换
			{//debug:因为num[n]不存在，所以i<n(不取等号)
				small_heap.pop();
				small_heap.push(nums[i]);				
			}
			i++; //后移，但不能超出
		}
		return small_heap.top();
	}
};

int main(){	
	std::vector<int> nums;
	int A[] = {5,2,4,1,3,6,0};
	int n = sizeof(A)/sizeof(A[0]);
	for(int i=0;i<n;i++)
	{
		nums.push_back(A[i]);
	}
	Solution solve;
	int reslut = solve.findKthLargest(nums,2);
	printf("为：%d\n",reslut);
	system("pause");
	return 0;
}