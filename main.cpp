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
100. Same Tree
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 -104 <= Node.val <= 104
*/

// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stP, stQ;
        TreeNode *cp = p;
        TreeNode *cq = q;
        while (cp || cq || !stP.empty() || !stQ.empty()){
            while (cp || cq){
                if (!cp || !cq || (cp->val != cq->val))
                    return false;
                stP.push(cp); stQ.push(cq);
                cp = cp->left;
                cq = cq->left;
            }
            cp = stP.top()->right; cq = stQ.top()->right;
            stP.pop(); stQ.pop();
        }
        return true;
    }


int main(){
     TreeNode *p = new TreeNode(1);
     p->left = new TreeNode(2);
     p->right = new TreeNode(1);

     TreeNode *q = new TreeNode(1);
     q->right = new TreeNode(1);
     q->right = new TreeNode(2);

    std::cout << boolalpha << isSameTree(p, q) << "\n";

}