#include "stdafx.h"
#include <stdlib.h>
#include <map>
#include <vector>

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
 

int main(int argc, _TCHAR* argv[])
{
	std::map<RandomListNode*,int> node_map; 
	std::vector<RandomListNode*> node_vec;//数组一样，根据下标值找到地址
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
	
	//map : key是地址，value是整数，从0开始。
	node_map[&a] = 0;
	node_map[&b] = 1;
	node_map[&c] = 2;
	node_map[&d] = 3;
	node_map[&e] = 4;

	//vec
	node_vec.push_back(&a);
	node_vec.push_back(&b);
	node_vec.push_back(&c);

	printf("%d ",node_map[e.random]);
	printf("%d ",node_vec[node_map[c.random]]->label);

	system("pause");
	return 0;
}

