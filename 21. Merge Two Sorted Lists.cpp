#include "stdafx.h"
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//21. Merge Two Sorted Lists
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *new_head = new ListNode(0);
		ListNode *ptr = new_head; //�ȱ���
		while (l1&&l2)
		{//�����е�ʱ��
			if (l1->val<l2->val)
			{
				new_head->next = l1;
				l1 = l1->next;
			}else
			{
				new_head->next = l2;
				l2 = l2->next;
			}
			new_head = new_head->next; //����
		}
		if (l1)
		{//ֻʣl1
			new_head->next = l1;
		}
		if (l2)
		{
			new_head->next = l2;
		}
		return ptr->next;
	}
};

int main(int argc, _TCHAR* argv[])
{
	
	ListNode a(1);
	ListNode b(2);
	ListNode c(4);

	ListNode d(1);
	ListNode e(3);
	ListNode f(4);

	//������
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	d.next = &e;
	e.next = &f;
	f.next = NULL;

	Solution solve;
	ListNode* result = solve.mergeTwoLists(&a,&d);
	//printf("\n");
	while(result){
		printf("%d ",result->val);
		result = result->next;
	}	

	system("pause");
	return 0;
}

