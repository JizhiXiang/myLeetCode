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
	bool hasCycle(ListNode *head) {
		std::set<ListNode*> node_set;
		while(head){			
			if (node_set.find(head)!=node_set.end())
			{//如果找到
				return true;
			}
			node_set.insert(head);
			head = head->next;
		}//没找到，则false
		return false;
	}
};

int main(int argc, _TCHAR* argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	//g.next = NULL;

	Solution solve;
	bool has_cycle = solve.hasCycle(&a);
	printf("%d\n",has_cycle);
	system("pause");
	return 0;
}

