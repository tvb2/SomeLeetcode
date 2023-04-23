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
110. Balanced Binary Tree. Easy
Given a binary tree, determine if it is 
height-balanced
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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

        //return maximum number of levels for the node
    int maxLevels(TreeNode* root, int levels){
        ++levels;
        int l = 0, r = 0;
        if (root->left || root->right){
            l = (root->left)?maxLevels(root->left, levels):0;
            r = (root->right)?maxLevels(root->right, levels):0;
        }
        else
            return levels;
        levels = std::max(l,r);
        return levels;
    }

    //using maxLevels function compare maximum number of levels for left and right branches
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int l = 0, r = 0;
        bool balanced = true;
        if (root->left || root->right){
            l = (root->left)?maxLevels(root->left, l):0;
            r = (root->right)?maxLevels(root->right,r):0;       
            balanced = balanced?(std::abs(l - r) <= 1):balanced;
            balanced = (root->left && balanced)?isBalanced(root->left):balanced;
            balanced = (root->right && balanced)?isBalanced(root->right):balanced;
        }
        return balanced;       
    }


int main(){
    // root = [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    
    root->right = new TreeNode(2);
    root->right->right= new TreeNode(3);
    root->right->right->right= new TreeNode(4);

    std::cout << boolalpha << isBalanced(root);
    std::cout << " complete\n";
}