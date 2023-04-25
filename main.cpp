#include <iostream>
#include <string>
#include <sstream>
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
113. Path Sum II. Medium
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
    //Level order tree creation
    void createLevels(TreeNode* &root, std::vector<std::vector<TreeNode*>> &nVect, int level){
        if (level == 0){//first (root) node
            root = nVect[level][0];
            createLevels(root, nVect, ++level);
        }
        if (level < nVect.size()){//proceed while level is below max
            if (nVect[level].size() > 1) {
                root->left = *nVect[level].begin();
                nVect[level].erase(nVect[level].cbegin());//delete elements after being used
            }
            if (root->left) createLevels(root->left, nVect, (level+1));
            
            if (nVect[level].size() > 1){
                root->right = *nVect[level].begin();
                nVect[level].erase(nVect[level].cbegin());
            } 
            if (root->right) createLevels(root->right, nVect, (level+1));
        }
        return;
    }

    /**
     * convert string to a vector of Nodes for level-order creation
     * Each element of vector represents a level in the tree
    */
    std::vector<std::vector<TreeNode*>> getNodesVector(std::string nodes){
        std::vector<std::vector<TreeNode*>> nVect;
        std::string temp;
        std::stringstream stream(nodes);
        int level = 0, count = 1;
        std::vector<TreeNode*> lvl;
        while (!stream.eof()){//read data from string stream delimited by commas
            int k = count;//add number of elements defined at previous level
            count = 0;//calculate possible number of elements in the next level (equals number of non-null elements)
            while (k > 0 && !stream.eof()){
                std::getline(stream, temp,',');
                if (temp == "null"){
                    lvl.emplace_back(nullptr);
                }
                else{
                    int val = std::stoi(temp);
                    lvl.emplace_back(new TreeNode(val, nullptr, nullptr));
                    count += 2;//if we come across a non-null element, possible leafs on the next level is two
                }
                --k;
            }
            //add a nullptr in the end - this will be required during building of the tree 
            //we will delete each element as we build the tree. And need to keep at least one element in order to keep the structure of the vector
            lvl.emplace_back(nullptr);
            nVect.emplace_back(lvl);
            lvl.clear();
        }
        return nVect;
    }

    /**
     * convert string representing a list of nodes to a binary tree represented by a root.
    */
    TreeNode* buildTree(std::string nodes){
        if (nodes.length() == 0)
            return new TreeNode;
        std::vector<std::vector<TreeNode*>> nVect = getNodesVector(nodes);
        
        int i = 0, level = 0;
        TreeNode* root;
        createLevels(root, nVect, level);
        return root;
}


    //recursively search left and right branches subtracting node values from targetSum and return result when we come to any end leaf
       void singlePathSum(TreeNode* root, int targetSum, std::vector<std::vector<int>> &res, std::vector<int> &t) {
        bool has = false;
        targetSum -= root->val;
        t.emplace_back(root->val);
        if (!root->left && !root->right){
            if (targetSum == 0){
                res.emplace_back(t);
                t.pop_back();
                has = true;
            }
            else{
                t.pop_back();
            }
        }
        if (root->left || root->right){
            if (root->left) singlePathSum(root->left, targetSum, res, t);
            if (root->right) singlePathSum(root->right, targetSum, res, t);
            t.pop_back();
        }
        return;
    }

    //recursively search left and right branches subtracting node values from targetSum and return result when we come to any end leaf
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> t;
        int i = 0;
        if (!root)
            return res;
        t.emplace_back(root->val);
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right){
            res.emplace_back(t);
            return res;
        }

        if (root->left) singlePathSum(root->left, targetSum, res, t);
        t.resize(1);
        if (root->right) singlePathSum(root->right, targetSum, res, t);
        return res;
    }

int main(){
    // std::string nodes = "1,2,3"; int targetSum = 5;
    // std::string nodes = "1,2,3,4,6,5,2,null,2,null,null,null,null,3"; int targetSum = 9;
    std::string nodes = "1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0"; int targetSum = 2;
    // std::string nodes = "5,4,8,11,null,13,4,7,2,null,null,5,1"; int targetSum = 22;
    // std::string nodes = "1,2,null,3,null,4,null,5"; int targetSum = 6;
    
    // std::string nodes = ""; int targetSum = 22;
    TreeNode* root = buildTree(nodes);
    
    vector<vector<int>> res = pathSum(root, targetSum);
    for (auto i:res){
        for (auto j:i){
            std::cout << j << " ";
        }
        std::cout <<"\n";
    }
    std::cout << " complete\n";
}