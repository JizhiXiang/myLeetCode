#include "stdafx.h"
#include <stdlib.h>
#include <stack>

class MinStack {
public:
	//155.MinStack
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data_stack.push(x);
		if (min_stack.empty())
		{
			min_stack.push(x);
		} 
		else if (x<min_stack.top()) //x比min_stack上面的还小
		{
			min_stack.push(x);
		}
		else{
			min_stack.push(min_stack.top());//把前面那个再放一次
		}
    }
    
    void pop() {
        data_stack.pop();
		min_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
	std::stack<int> data_stack;
	std::stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
int main(){
	MinStack S;
	S.push(5);
	S.push(4);
	S.push(6);
	S.push(1);
	printf("getMin=%d\n",S.getMin());
	S.pop();
	printf("getMin=%d\n",S.getMin());

	system("pause");
    return 0;
}