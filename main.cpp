#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

//725. Split Linked List in Parts

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
        std::vector<ListNode*> result;
        std::vector<int> cont;
        //first read all elements into a vector
        while(!(head == nullptr)){
            cont.emplace_back(head->val);
            head = head->next;
        }
        int f = cont.size()/k;
        int s = cont.size()%k;
        int count = 0;
        //the case when there will be empty lists
        if (f == 0){
            for (int i = 0; i < s; ++i){
                ListNode *n = new ListNode(cont[i]);
                result.emplace_back(n);
            }
            for (int i = result.size(); i < k; ++i){
                ListNode *n = nullptr;
                result.emplace_back(n);
            }
            // al singles plus whatever is the remainder
        }

        //create normal lists
        else{
            for (int i = 0; i < k; ++i){
                int l = (s > 0)?(f+1):f; //the size of current list
                --s;
                int start = count;
                ListNode *n = new ListNode(cont[start]);
                ++count;
                ListNode *c = n;
                for (int j = 1; j < l; ++j){
                    ListNode *m = new ListNode(cont[start+j]);
                    c->next = m;
                    c = m;
                    ++count;
                }
                result.emplace_back(n);
            }
        }
        return result;
    }


int main(){
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    int k = 16;

    ListNode *head = createList(v);

    ListNode *l = head;
    printList(l);

    std::vector<ListNode*> result = splitListToParts(head, k);
    std::cout << "the size of the result vector is: " << result.size() << "\n";

    for (size_t i = 0; i < result.size(); ++i){
        ListNode *m = result[i];
        printList(m);
        std::cout << "\n";
    }


    std::cout << " \ncomplete\n";
}