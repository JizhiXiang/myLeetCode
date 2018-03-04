#include "stdafx.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
bool cmp(const ListNode *a,const ListNode *b){//��С����
	return a->val<b->val;
}
//23. Merge k Sorted Lists
class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		std::vector<ListNode*> node_vec;  //�����еĽڵ���װ��ȥ
		for (int i=0;i<lists.size();i++)
		{
			ListNode *head = lists[i];//��i��,ͷ���
			while(head){ //ȫѹ��ȥ
				node_vec.push_back(head);
				head = head->next;
			}
		}
		if (node_vec.size()==0)
		{//û��
			return NULL;
		}
		//node_vec.push_back(0); //��Ϊ���һ���ڵ�
		//����
		std::sort(node_vec.begin(),node_vec.end(),cmp);
		for (int i=1;i<node_vec.size();i++)
		{//�����һ������
			node_vec[i-1]->next = node_vec[i];
		}
		node_vec[node_vec.size()-1] = NULL;
		return node_vec[0];
	}
};

int main(int argc, _TCHAR* argv[])
{
	
	ListNode a(1);
	ListNode b(2);
	ListNode c(4);

	ListNode d(1);
	ListNode e(3);
	ListNode f(10);
	
	ListNode g(2);
	ListNode h(7);

	//������
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	d.next = &e;
	e.next = &f;
	f.next = NULL;

	g.next = &h;
	h.next = NULL;

	Solution solve;
	std::vector<ListNode*> lists;
	lists.push_back(&a);
	lists.push_back(&d);
	lists.push_back(&g);
	ListNode* result = solve.mergeKLists(lists);	
	while(result){
		printf("%d ",result->val);
		result = result->next;
	}	

	system("pause");
	return 0;
}

