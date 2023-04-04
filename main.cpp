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
102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
/// @brief recursively traverse the tree, keeping track of at what level we are
/// @param root 
/// @param result 
/// @param level keeps track of what level we are at. It is incremented/decremented according to going down/up the tree 
void helper (TreeNode* root, std::vector<std::vector<int>> & result, int &level){
    if (root){
        std::vector<int> t{root->val};
        if (result.size() < level){
            result.emplace_back(t);
        }
        else{
            result[level - 1].emplace_back(root->val);
        }
        ++level;
        helper(root->left,result, level);
        ++level;
        helper(root->right, result, level);
    }
    --level;

}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    int level = 1;
    helper(root, result, level);
    return result;    
}

int main(){
    //{[3,9,20,null,null,15,7]}
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(6);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> result = levelOrder(root);
    for (auto i:result){
        for (auto j:i){
            std::cout << j << " ";
        }
        std::cout <<"\n";
    }
}