#include "stdafx.h"
#include <stdlib.h>
#include <vector>

class Solution {
public:
	bool canJump(std::vector<int>& nums) {
		std::vector<int> index;
		for (int i=0;i<nums.size();i++)
		{
			index.push_back(nums[i]+i); //��������index[i]��λ��
		}
		int jump=0; //��0��ʼ����index����
		int max_index = index[0]; //��ʼ��
		while (jump<index.size()&&jump<=max_index) //jump��indexĩβ ���� jump>max_index������ѭ��
		{
			if (max_index<index[jump]) //Ҫȡ���
			{
				max_index = index[jump];
			}
			jump++; //����
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