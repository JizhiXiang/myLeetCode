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
		std::vector<RandomListNode*> node_vec;//数组一样，根据下标值找到地址
		RandomListNode *pre=head;
		int i =0;
		while(pre){
			node_vec.push_back(new RandomListNode(pre->label)); //新建节点
			node_map[pre] = i; //构建map
			pre = pre->next;
			i++;
		}
		node_vec.push_back(0); //为了在最后一个是0
		
		i = 0; 
		pre = head; //再重头来
		while(pre){			
			node_vec[i]->next = node_vec[i+1];  //连起来
			if (pre->random) //不为空时
			{
				int id = node_map[pre->random]; //找到id
				//printf("%d ",id);
				node_vec[i]->random = node_vec[id]; //连起random,node_vec[id]就是第i个节点对应的random值
			}
			pre = pre->next;
			i++;
		}
		//printf("%d ",node_vec[1]->random->label);		
		//好复杂啊。
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

	//连起来
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	//random初始化
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

