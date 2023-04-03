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
876. Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    ListNode* middleNode(ListNode* head) {
        if (!head)
            return head;
        std::vector<ListNode*> vec;
        while (head)
        {
            vec.push_back(new ListNode(head->val, head->next));
            head = head->next;
        }
        return vec[vec.size()/2];
    }



int main(){
    //head = [1,2,3,4,5]
    //1,2,3,4,5,6
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    
    ListNode* result = middleNode(head);
    std::cout <<" End\n";

}