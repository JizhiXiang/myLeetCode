#include "stdafx.h"
#include <stdlib.h>
#include <map>
#include <vector>

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 
//138. Copy List with Random Pointer
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		std::map<RandomListNode*,int> node_map; 
		std::vector<RandomListNode*> node_vec;//����һ���������±�ֵ�ҵ���ַ
		RandomListNode *pre=head;
		int i =0;
		while(pre){
			node_vec.push_back(new RandomListNode(pre->label)); //�½��ڵ�
			node_map[pre] = i; //����map
			pre = pre->next;
			i++;
		}
		node_vec.push_back(0); //Ϊ�������һ����0
		
		i = 0; 
		pre = head; //����ͷ��
		while(pre){			
			node_vec[i]->next = node_vec[i+1];  //������
			if (pre->random) //��Ϊ��ʱ
			{
				int id = node_map[pre->random]; //�ҵ�id
				//printf("%d ",id);
				node_vec[i]->random = node_vec[id]; //����random,node_vec[id]���ǵ�i���ڵ��Ӧ��randomֵ
			}
			pre = pre->next;
			i++;
		}
		//printf("%d ",node_vec[1]->random->label);		
		//�ø��Ӱ���
		return node_vec[0];
	}
};

int main(int argc, _TCHAR* argv[])
{
	
	RandomListNode a(6);
	RandomListNode b(3);
	RandomListNode c(1);
	RandomListNode d(7);
	RandomListNode e(2);

	//������
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	//random��ʼ��
	a.random = &c;
	b.random = &d;
	c.random = &c;
	d.random = NULL;
	e.random = &d;

	Solution solve;
	RandomListNode* result = solve.copyRandomList(&a);
	//printf("\n");
	while(result){
		printf("%d ",result->label);
		result = result->next;
	}	

	system("pause");
	return 0;
}

