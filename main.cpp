#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
#include <iterator>
#include <functional>
#include <stack>
#include <queue>
using namespace std;

/*
232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as 
long as you use only a stack's standard operations.

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/

class MyQueue {
public:
    std::stack<int> s1;
    std::stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int t = 0, pop = 0;
        for (size_t i = s1.size(); i > 0; --i){
            if (s1.size() == 1){
                pop = s1.top();
                s1.pop();
                break;
            }
            s2.push(s1.top());
            s1.pop();
        }
        for (size_t i = s2.size(); i > 0; --i){
            s1.push(s2.top());
            s2.pop();
        }
    return pop;
    }
    
    int peek() {
        int t = 0, peek = 0;
        for (size_t i = s1.size(); i > 0; --i){
            if (s1.size() == 1){
                peek = s1.top();
                break;
            }
            s2.push(s1.top());
            s1.pop();
        }
        for (size_t i = s2.size(); i > 0; --i){
            s1.push(s2.top());
            s2.pop();
        }
    return peek;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
	std::vector<int> vec {4, 5, 6, 7};
    MyQueue* obj = new MyQueue();
    for (auto x:vec)
        obj->push(x);
    int param_2 = obj->pop();
    std::cout << "p2: " << param_2 << "\n";
    int param_3 = obj->peek();
    std::cout << "p3: " << param_3 << "\n";
    bool param_4 = obj->empty();
 
}