#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = n-m+1;		
		int len2 = len;
		ListNode *raw_head,*pre_head,*m_head;
		raw_head = head;
		pre_head = NULL; //�ж��Ƿ�ӵ�һ����
		m_head = NULL;  //����Ϊ�˳�ʼ��
		m_head = head;
		while (head&&--m)
		{
			pre_head = head;
			head = head->next;
			m_head = pre_head->next;
		}
		ListNode *n_tail,*tail;
		while (head&&len--)
		{
			n_tail = head;
			head = head->next;
			tail = n_tail->next;
			//printf("%d ",len);
		}
		//pre_head->next = n_tail;
		ListNode *new_head = NULL; //�µ�ͷ���
		ListNode *modify_tail = m_head; //��ʱ��ŵ������
		while (m_head&&len2--)
		{
			ListNode *tmp_next = m_head->next; //���ݺ����Ǹ�
			m_head->next = new_head;
			new_head = m_head;
			m_head = tmp_next;
		}
		modify_tail->next = tail;
		if (pre_head)  //������Ǵӵ�һ���Ϳ�ʼ����
		{
			pre_head->next = new_head;
		}
		else
		{
			raw_head = new_head;
		}		
		return raw_head;
    }
	//TM���ڴ����������У�����˼·��д���죬д����shiһ���Ĵ��룬��debug����
};

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
	
	Solution solve;
	ListNode *head = &a;
	head = solve.reverseBetween(&a,1,3);
	while (head)
	{
		printf("%d ",head->val);
		head = head->next;
	}
	return 0;
}