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
#include <iomanip>
#include <set>
using namespace std;

/*
148. Sort List. Medium
Given the head of a linked list, return the list after sorting it in ascending order.

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

Follow up: Can you sort the linked list in O(n logn)
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    ListNode* divide(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* last = head;
        if (!fast->next){
            return slow;
        }
        if (fast->next && !fast->next->next){
            slow = slow->next;
            last->next = nullptr;
            return slow;
        }
        while (fast->next && fast->next->next){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last->next = nullptr;
        
        return slow;
    }

    ListNode * merge(ListNode* left, ListNode* right){
        ListNode* ptr = new ListNode(0);
        ListNode* head = ptr;
        while (left && right){
            if (left->val < right->val){
                ptr->next = left;
                left = left->next;
            }
            else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if (left)
            ptr->next = left;
        else
            ptr->next = right;
    return head->next;
    }

    //implementing editorial solution: divide and merge algorithm:
    //recursively divide list into two ~equal parts until only one element is left
    //then merge left and right parts comparing elements
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* m = divide(head);
        ListNode* l = sortList(head);
        ListNode* r = sortList(m);
        return merge(l, r);
    }


int main(){
ListNode* head = new ListNode(5);
head->next = new ListNode(-1);
// head->next->next = new ListNode(3);
// head->next->next->next = new ListNode(4);
// head->next->next->next->next = new ListNode(0);
ListNode* result = sortList(head);
std::cout <<  " end\n";
}