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
	//160. Intersection of Two Linked Lists_second_way
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		std::set<ListNode*> node_set;
		while(headA){
			node_set.insert(headA);
			headA = headA->next;
		}
		while(headB){
			if (node_set.find(headB)!=node_set.end())
			{//第一次找到节点
				return headB;
			}
			headB = headB->next;
		}
		return NULL;
	}
};
int main(int argc, _TCHAR* argv[])
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
	i.next = &c;

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

