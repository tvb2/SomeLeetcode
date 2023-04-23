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
543. Diameter of Binary Tree. Easy
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
The number of nodes in the tree is in the range [1, 104].
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

    //return maximum number of levels for the node
    int maxLevels(TreeNode* root, int levels){
        ++levels;
        int l = 0, r = 0;
        if (root->left || root->right){
            l = (root->left)?maxLevels(root->left, levels):1;
            r = (root->right)?maxLevels(root->right, levels):1;
        }
        else
            return levels;
        levels = std::max(l,r);
        return levels;
    }

     int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0, diaL = 0, diaR = 0;
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int l = 0, r = 0;
        if (root->left || root->right){
            l = (root->left)?maxLevels(root->left, l):0;
            r = (root->right)?maxLevels(root->right,r):0;
            diameter = (diameter < (l + r))?(l + r):diameter;
            diaL = (root->left)?diameterOfBinaryTree(root->left):diameter;
            diaR = (root->right)?diameterOfBinaryTree(root->right):diameter;
            diameter = std::max({diameter, diaL, diaR});
            // balanced = (root->left && balanced)?isBalanced(root->left):balanced;
            // balanced = (root->right && balanced)?isBalanced(root->right):balanced;
        }
        return diameter;
    }


int main(){
    // root = [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
            root->left->left = new TreeNode(1);
            root->left->right = new TreeNode(3);
                root->left->right->left = new TreeNode(2);
                    root->left->right->left->left = new TreeNode(1);
                    root->left->right->left->right = new TreeNode(8);
                root->left->right->right= new TreeNode(4);
            
        // root->right = new TreeNode(7);
        //     root->right->left = new TreeNode(6);
        //     root->right->right = new TreeNode(9);
    
    std::cout << diameterOfBinaryTree(root);
    std::cout << " complete\n";
}