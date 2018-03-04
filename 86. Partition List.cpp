#include "stdafx.h"
#include <stdlib.h>
#include <set>

struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		//86. Partition List
		//巧用临时头结点
		ListNode less_head(0);
		ListNode more_head(0);
		ListNode *less_ptr = &less_head;
		ListNode *more_ptr = &more_head;
		while(head){
			if (head->val<x)
			{
				less_ptr->next = head;
				less_ptr = head;//右移
			} 
			else
			{				
				more_ptr->next = head;
				more_ptr = head; 
			}
			head = head->next;
		}
		//合并:less的右边接着more的左边
		less_ptr->next = more_head.next;
		more_ptr->next = NULL;  //注意
		return less_head.next;
	}
};

int main(int argc, _TCHAR* argv[])
{
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);	

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode *result = solve.partition(&a,3);
	while(result){
		printf("%d\n",result->val);
		result = result->next;
	}	
	system("pause");
	return 0;
}

