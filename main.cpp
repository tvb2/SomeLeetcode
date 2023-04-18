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
328. Odd Even Linked List. Medium
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        if (!head->next)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* second = even;
        while (even && odd && even->next && odd->next){
                odd->next = odd->next->next;
                odd = odd->next;
            if (even->next->next){
                even->next = even->next->next;
                even = even->next;
            }
            else{
                even->next = nullptr;
                even = even->next;
            }
        }
            if (even){
                even->next = nullptr;
                even = even->next;
            }
        odd->next = second;
        return head;
    }


int main(){
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
head->next->next->next = new ListNode(4);
head->next->next->next->next = new ListNode(5);
ListNode* result = oddEvenList(head);
std::cout <<  " end\n";
}