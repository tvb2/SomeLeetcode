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
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
            helper(root->left, result);
            result.push_back(root->val);
            helper(root->right, result);
        }
    }

    //recursive version using helper
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(root, result);
        return result;
    }
    //stack version
    // vector<int> inorderTraversal(TreeNode* root) {
    //     std::vector<int> res;
    //     std::stack<TreeNode*> stack;
    //     TreeNode *curr = root;
    //     while (curr != nullptr || !stack.empty()) {
    //         while (curr != nullptr) {
    //             stack.push(curr);
    //             curr = curr->left;
    //         }
    //         curr = stack.top();
    //         stack.pop();
    //         res.push_back(curr->val);
    //         curr = curr->right;
    //     }
    //     return res;
    // }


int main(){

    // {1,null,2,3};
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::vector<int> result = inorderTraversal(root);
    
    for (auto i:result)
        std::cout << i << "\n";

 
}