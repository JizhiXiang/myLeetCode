#include "stdafx.h"
#include <stdlib.h>
#include <stack>
#include <queue>

bool check_is_valid_order(std::queue<int> &order)
{	//poj1363.check_is_valid_order
	std::stack<int> S;
	int num = order.size();
	for (int i=1;i<=num;i++)
	{
		S.push(i);
		while (!S.empty() && S.top()==order.front()) //栈顶和队头相等,则都弹出.可以多次
		{
			S.pop();
			order.pop();
		}
	}
	if (S.empty()&&order.empty())
	{
		return true;
	}
	return false;
}

int main(){
	std::queue<int> Q;
	Q.push(4);
	Q.push(3);	
	Q.push(5);
	Q.push(2);	
	Q.push(1);
	printf("%d\n",check_is_valid_order(Q));
	system("pause");
    return 0;
}