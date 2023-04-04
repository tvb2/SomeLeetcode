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
98. Validate Binary Search Tree. Medium
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1
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
 
    //using recursive approach
    bool helper (TreeNode* root, long long  min, long long  max){
        //if we have reached the end of the tree, obviousely we are good
        if (!root)
            return true;
        //if left element is not less than root - not Valid
        if (root->left && (root->left->val >= root->val || root->left->val >= max || root->left->val <= min))
            return false;
        //if right element is not greater than root - not Valid
        if (root->right && (root->right->val <= root->val || root->right->val >= max || root->right->val <= min))
            return false;
        //recursively check both left and right branches. Both must be valid.
        return (helper(root->left, min, root->val) && helper(root->right, root->val, max));
    }


    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        //long long is used to take into account the case when one of the values is min or max and it should be valid
        long long min = static_cast<long long>(std::numeric_limits<int>::min()) - 1; 
        long long max = static_cast<long long>(std::numeric_limits<int>::max()) + 1;
        return (helper(root, min, max));
    }

int main(){
    // 3,1,5,0,2,4,6  -2147483648,null,2147483647
    TreeNode* root = new TreeNode(-2147483648);
    // root->left = new TreeNode(26);
    // root->left->left = new TreeNode(19);
    // root->left->left->right = new TreeNode(27);
    
    root->right = new TreeNode(2147483647);
    // root->right->right= new TreeNode(56);
    // root->right->right = new TreeNode(7);
    
    std::cout<< boolalpha << isValidBST(root) <<"\n";
}