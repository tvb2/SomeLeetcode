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
145. Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

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
            if(root==nullptr)
                return;
            helper(root->left, result);
            helper(root->right,result);
            result.push_back(root->val);
        }
    }

    //recursive version using helper
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        helper(root, result);
        return result;
    }
    //stack version
    //    vector<int> postorderTraversal(TreeNode* root) {    
    //    std::vector<int> result;
    //    std::stack<TreeNode*> st;
    //    TreeNode *current = root;
    //    while (current != nullptr || !st.empty()){
    //         if(current != nullptr){
    //             st.push(current);
    //             result.emplace(result.begin(), current->val);
    //             current = current->right;
    //         }
    //         else{
    //             TreeNode *temp = st.top();
    //             current = temp->left;
    //             st.pop();
    //         }
    //    }
    //    return result;
    // }


int main(){

    // {1,null,2,3};
    TreeNode *root = new TreeNode(25);
    root->left = new TreeNode(15);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(22);
    
    root->right = new TreeNode(50);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(70);

    std::vector<int> result = postorderTraversal(root);
    
    for (auto i:result)
        std::cout << i << "\n";

 
}