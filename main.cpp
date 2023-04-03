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
141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
        bool hasCycle(ListNode *head) {
            if (!head)
                return false;
                std::set<ListNode*> s;
                while (head){
                    if (s.find(head) == s.end())
                        s.emplace(head);
                    else
                        return true;
                    head = head->next;

                }
            return false;
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
    
    // ListNode* result = hasCycle(head);
    std::cout<< boolalpha << hasCycle(head) <<" End\n";

}