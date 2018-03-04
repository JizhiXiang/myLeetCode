// algorithm1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//160. Intersection of Two Linked Lists
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0,lenB = 0;
		ListNode *tempA=headA,*tempB=headB;
		while(tempA){
			lenA++;
			tempA = tempA->next;
		}
		while(tempB){
			lenB++;
			tempB = tempB->next;
		}		
		int m = 0; //记住多余值
		if (lenA>lenB)
		{
			m = lenA-lenB;
			while(headA && m--){
				headA = headA->next;
			}
			while(headA&&headB){
				if (headA==headB)
				{//相等了，则返回，表示找到了
					return headB;
				}
				headA = headA->next;
				headB = headB->next;
			}

		}else
		{  //B比A长(b>=a)
			m = lenB-lenA;
			while(headB && m--){
				headB = headB->next;//走到相同长度的位置
			}
			while(headA&&headB){
				if (headA==headB)
				{//相等了，则返回，表示找到了
					return headA;
				}
				headA = headA->next;
				headB = headB->next;
			}
		}
		return NULL;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	ListNode f(7);
	ListNode g(8);
	ListNode h(9);
	ListNode i(10);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	f.next = &g;
	g.next = &h;
	h.next = &i;
	//i.next = &c;
	Solution solve;
	ListNode *head = solve.getIntersectionNode(&a,&f);
	printf("%d\n",head->val);
/*	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}*/	
	
	system("pause");	
	return 0;
}

