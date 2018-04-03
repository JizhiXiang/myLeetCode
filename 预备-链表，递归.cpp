#include "stdafx.h"
#include <stdlib.h>
#include<vector>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

void add_to_vector(ListNode  *head,std::vector<int> &vec){
	if (!head)//¿Õ
	{
		return;
	}
	vec.push_back(head->val);
	add_to_vector(head->next,vec);
}

//Ô¤±¸-Á´±í£¬µÝ¹é
int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = NULL;
	ListNode *head = &a;
	ListNode *head2 = &a;
	while (head)
	{
		printf("%d ",head->val);
		head = head->next;
	}
	printf("\n");
	std::vector<int> vec;
	add_to_vector(head2,vec);
	for (int i=0;i<vec.size();i++)
	{
		printf("%d ",vec[i]);
	}
	system("pause");
	return 0;
}