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
19. Remove Nth Node From End of List. Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* c = head;
        ListNode* nth = head;
        int count = 0;
        while (c->next){
            c = c->next;
            ++count;
            if (count > n)
                nth = nth->next;
        }
       if (count < n)
        head = head->next;
       else
        nth->next = nth->next->next;
        return head;
    }


int main(){
ListNode* head = new ListNode(1);
// = [1,2,3,4,5], n = 2
// head->next = new ListNode(2);
// head->next->next = new ListNode(3);
// head->next->next->next = new ListNode(4);
// head->next->next->next->next = new ListNode(5);
int n = 1;
ListNode *result = removeNthFromEnd(head, n);
std::cout << "end\n";
}