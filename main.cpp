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
437. Path Sum III. Medium
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
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
    //using quee to check intermediate combinations. In the end pop quee to see if previous shorter combinations make up a targetSum
       int singlePathSum(TreeNode* root, int targetSum, long long sum, std::queue<int> q) {
        int count = 0;
        q.emplace(root->val);
        sum += (long long)root->val;
        if (sum == targetSum)
            ++count;
        if (root->left || root->right){
            if (root->left) count += singlePathSum(root->left, targetSum, sum, q);
            if (root->right) count += singlePathSum(root->right, targetSum, sum, q);
        }
        while (!q.empty()){
            if (q.size() == 2){
                if (root->val == targetSum) ++count;
                break;
            }
            sum -= q.front();
            count += (sum == targetSum)?1:0;
            q.pop();
        }
        return count;
    }

    //recursively search left and right branches subtracting node values from targetSum and return result when we come to any end leaf
    //using quee to check intermediate combinations. 
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        int count = 0;
        std::queue<int> q;
        q.emplace(root->val);
        long long sum = root->val;
        if (sum == targetSum)
            ++count;
        if (!root)
            return count;
        if (root->left) count += singlePathSum(root->left, targetSum, sum, q);
        if (root->right) count += singlePathSum(root->right, targetSum, sum, q);
        return count;
    }


int main(){
    // std::string nodes = "1,2,3"; int targetSum = 5;// 0
    // std::string nodes = "5"; int targetSum = 5;//1
    // std::string nodes = "1,2"; int targetSum = 0;//0
    // std::string nodes = "1,2"; int targetSum = 1;//1
    // std::string nodes = "0,1,1"; int targetSum = 1;//4
    // std::string nodes = "1,2,3,4,6,5,2,null,2,null,null,null,null,3"; int targetSum = 9;//4
    // std::string nodes = "1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0"; int targetSum = 2;//13
    // std::string nodes = "1,0,null,null,2,-1,0"; int targetSum = 2;//5
    // std::string nodes = "5,4,8,11,null,13,4,7,2,null,null,5,1"; int targetSum = 22;//3
    // std::string nodes = "1,2,null,3,null,4,null,5"; int targetSum = 6;//1
    // std::string nodes = "10,5,-3,3,2,null,11,3,-2,null,1"; int targetSum = 8;//3
    std::string nodes = "1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000,null,1000000000"; 
    int targetSum = 1000;//3
    
    // std::string nodes = ""; int targetSum = 22;
    TreeNode* root = buildTree(nodes);
    
    std::cout<<  pathSum(root, targetSum);
    std::cout << " complete\n";
}