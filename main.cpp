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
226. Invert Binary Tree. Easy
Given the root of a binary tree, invert the tree, and return its root.
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

//Definition of a ListNode
/*
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
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


    //recursively drill down the tree and get left and right nodes. Then swap them
     TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        if (root->left || root->right){
            TreeNode* left = (root->left)?invertTree(root->left):nullptr;
            TreeNode* right = (root->right)?invertTree(root->right):nullptr;
            root->right = left;
            root->left = right;
        }
        return root;
    }


int main(){
    // root = [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right= new TreeNode(9);

    TreeNode* res = invertTree(root);
    std::cout << "complete\n";
}