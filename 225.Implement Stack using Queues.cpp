#include "stdafx.h"
#include <stdlib.h>
#include <queue>

class MyStack {
public:
	//225.Implement Stack using Queues
	//栈：后进先出
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> tmp_queue;
		while(!data_queue.empty()){
			tmp_queue.push(data_queue.front());//从队头出去,放到tmp_queue中
			data_queue.pop();
		}
		data_queue.push(x); //把x放到队列中
		while(!tmp_queue.empty()){  //又把它放回data_queue中
			data_queue.push(tmp_queue.front());
			tmp_queue.pop();
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = data_queue.front();
		data_queue.pop();
		return a;
    }
    
    /** Get the top element. */
    int top() {
        return data_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data_queue.empty();
    }
private:
	std::queue<int> data_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(){
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	printf("top=%d\n",S.top());
	S.pop();
	printf("pop=%d\n",S.pop());	
	printf("empty=%d\n",S.empty());
	S.pop();
	printf("empty=%d\n",S.empty());

	system("pause");
    return 0;
}