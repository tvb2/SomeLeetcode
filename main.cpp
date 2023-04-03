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
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    ListNode* reverseList(ListNode* head) {
        //if empty head, return itself
        if (!head)
            return head;
        ListNode *r = new ListNode (head->val);
        head = head->next;
        while (head != nullptr){
            r = new ListNode(head->val, r);
            head = head->next;
        }
        return r;
    }



int main(){
    //head = [1,2,3,4,5]
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* result = reverseList(head);
    std::cout <<" End\n";

}