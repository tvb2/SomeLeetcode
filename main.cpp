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
234. Palindrome Linked List. Easy
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.
 The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    bool isPalindrome(ListNode* head) {
        std::deque<int> l;
        while(head){
            l.push_back(head->val);
            head = head->next;    
        }
        while (l.size() > 1){
            if (l.back() != l.front())
                return false;
            l.pop_back(); l.pop_front();
        }
    return true;
    }


int main(){
ListNode* head = new ListNode(1);
// = [1,2,3,4,5], n = 2
// head->next = new ListNode(2);
// head->next->next = new ListNode(2);
// head->next->next->next = new ListNode(1);
// head->next->next->next->next = new ListNode(5);
std::cout << boolalpha << isPalindrome(head) <<  " end\n";
}