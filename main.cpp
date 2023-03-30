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
144. Binary Tree Preorder Traversal
Given the root of a binary tree, return the preorder traversal of its nodes' values.

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    
    void helper (TreeNode *root, std::vector<int> &result){
        if (root != nullptr){
            result.push_back(root->val);
            helper(root->left, result);
            helper(root->right, result);
        }
    }

    //recursive version using helper
    // vector<int> preorderTraversal(TreeNode* root) {
    //     std::vector<int> result;
    //     helper(root, result);
    //     return result;
    // }
    //stack version
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode *curr = root;
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
        return res;
    }


int main(){

    // {1,null,2,3};
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    std::vector<int> result = preorderTraversal(root);
    
    for (auto i:result)
        std::cout << i << "\n";

 
}