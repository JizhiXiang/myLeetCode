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
		//��״̬��������
		int const START = 0;
		int const UP = 1;
		int const DOWN = 2;
		int i=1;//�ӵ�2����ʼ
		int status = START;
		int result = 1;//���ؽ��
		while (i<nums.size())
		{
			switch (status)
			{
			case START:
				if (nums[i]>nums[i-1]){ //����ı�ǰ��Ĵ�����UP
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
				//������������ȣ����״̬�����䡣
				break;
			case DOWN:
				if (nums[i]>nums[i-1]){ 
					status = UP;
					result++;
				}
			}
			i++;//ÿ�ζ�Ҫ��������һ��
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
	printf("���Ϊ%d\n",result);
	system("pause");
	return 0;
}