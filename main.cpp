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
using namespace std;

/*
235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as 
descendants (where we allow a node to be a descendant of itself).”

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
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

    bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode &result){
        int mid = 0, left = 0, right = 0;
        if (!root)
            return false;
        left = lca(root->left, p, q, result);
        right = lca(root->right, p, q, result);
        if (root->val == p->val || root->val == q->val)
            mid = 1;

        if (left + mid + right >= 2){
            result.val = root->val;
        }
        return (left || mid || right);
    }
    
    //implementing editorial solution using recursive approach and three flags: mid, left & right. 
    //LCA is when 2oo3 flags are set to 1;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode result;
        lca(root, p, q, result);
        TreeNode * res = new TreeNode(result.val);
        return res;
    }

int main(){
    // [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    //root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    //3,5,1,6,2,0,8,null,null,7,4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right= new TreeNode(4);
    
    root->right = new TreeNode(1);
    root->right->right= new TreeNode(0);
    root->right->left= new TreeNode(8);

    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(4);
    
    TreeNode* result = lowestCommonAncestor(root, p, q);
    std::cout<< result->val <<"\n";
}