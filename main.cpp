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
142. Linked List Cycle II
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.

Do not modify the linked list.
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return head;
        std::unordered_set<ListNode*> s;
        while (head){
            auto it = s.find(head);
            if (it == s.end())
                s.emplace(head);
            else
                return head;
            head = head->next;
        }
        return head;
    }



int main(){
    //head = [1,2,3,4,5]
    //1,2,3,4,5,6
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode * c = head->next;
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = c;

    // head->next->next->next->next = new ListNode(5);
    
    ListNode* result = detectCycle(head);
    std::cout<< " End\n";

}