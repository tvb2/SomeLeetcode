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
112. Path Sum. Easy
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.

A leaf is a node with no children.

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        bool has = false;
        if (root && !has){
            targetSum -= root->val;
            if (!root->left && !root->right)
                return targetSum == 0;            
        }
        if (root->left) has = has || hasPathSum(root->left, targetSum);
        if (root->right) has = has || hasPathSum(root->right, targetSum);
        return has;
    }

int main(){
    // std::string nodes = "1,2,3"; int targetSum = 5;
    // std::string nodes = "5,4,8,11,null,13,4,7,2,null,null,5,1"; int targetSum = 22;
    std::string nodes = ""; int targetSum = 22;
    TreeNode* root = buildTree(nodes);
    
    std::cout<< boolalpha << hasPathSum(root, targetSum) << " complete\n";
    std::cout << " complete\n";
}