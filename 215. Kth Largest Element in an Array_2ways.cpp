#include "stdafx.h"
#include <stdlib.h>
#include <queue>
#include <vector>

//215. Kth Largest Element in an Array
class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::priority_queue<int,std::vector<int>,std::greater<int>> small_heap;//С����
		int n = nums.size();
		//�Ȱ�ǰ��k���Ž�С����
		int i;
		for(i=0;i<k;i++)
		{
			small_heap.push(nums[i]);
		}
		//����һ����ʼ,ʵ����i�Ѿ��Զ�+1��
		while(i<n){
			if(nums[i]>small_heap.top()) //�¼ӵıȶ�����С��Ҫ�󣬾��滻
			{//debug:��Ϊnum[n]�����ڣ�����i<n(��ȡ�Ⱥ�)
				small_heap.pop();
				small_heap.push(nums[i]);				
			}
			i++; //���ƣ������ܳ���
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
	printf("Ϊ��%d\n",reslut);
	system("pause");
	return 0;
}