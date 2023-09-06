#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Definition for singly-linked list.
 */
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
    void printList(ListNode *l){
        while(!(l == nullptr)){
        std::cout << l->val << " ";
        l = l->next;
    }
 }
    ListNode * createList(std::vector<int> &v){
    ListNode *head = new ListNode();
    if (v.size() == 0){
        head = nullptr;
        return head; 
    }
    
    ListNode *c = head;
    for (size_t i = 0; i < v.size(); ++i){
        c->val = v[i];
        if (i+1 < v.size()){
            c->next = new ListNode;
            c = c->next;
        }
    }
    return head;
}

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<ListNode*> result{};
        return result;
    }


int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    ListNode *head = createList(v);

    ListNode *l = head;
    printList(l);


    std::cout << " \ncomplete\n";
}