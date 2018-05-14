#include "stdafx.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int index = 0;
		int left = 0;
		int right = nums.size();
		while(left<=right){
			int mid = (left+right)/2;
			if (target == nums[mid])
			{
				return mid;
			}
			else if (target<nums[mid]){
				if (mid==left||target>nums[mid-1])
				{
					index = mid;					
				}
				right = mid - 1;
			}
			else if (target>nums[mid])
			{
				if (mid==right||target<nums[mid+1])
				{
					index = mid +1;
				}
				left = mid + 1;
			}
		}
		return index;
	}
};

int main(){

	system("pause");
	return 0;
}