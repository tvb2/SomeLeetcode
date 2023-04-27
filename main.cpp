#include <iostream>
#include <vector>
using namespace std;

/*
74. Search a 2D Matrix. Medium
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
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
/*
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
/*
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
*/
    /**
     * convert string representing a list of nodes to a binary tree represented by a root.
    */
/*
    TreeNode* buildTree(std::string nodes){
        if (nodes.length() == 0)
            return new TreeNode;
        std::vector<std::vector<TreeNode*>> nVect = getNodesVector(nodes);
        
        int i = 0, level = 0;
        TreeNode* root;
        createLevels(root, nVect, level);
        return root;
}
*/
    
    //binary search
    bool search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, ind = l;
        ind = l + (r - l)/2;
        while ( l >=0 && r < nums.size() && l <= r){
            ind = l + (r - l)/2;
            if (nums[ind] == target){
                return true;
            }
            if (nums[ind] > target){
                r = ind -1;
            }
            else {
                l = ind +1;
            }
        }
        return false;
    }

    bool searchMatrix(std::vector<std::vector<int>> &m, int target) {
        //for single line m search the first row
        if (m.size() == 1){
            return search(m[0], target);
        }
        int size = m.size();
        int min = 0, max = size - 1, ind = min;
        while (min >= 0 && max < size && min <= max){
            ind = min + (max - min)/2;
            if (m[ind][0] == target){
                return true;
            }
            if (m[ind][0] > target){
                max = ind - 1;
            }
            else{
                if (m[ind][m[ind].size() - 1] < target)
                    min = ind + 1;
                else{
                    return search (m[ind], target);
                }
            }
        }
        if (ind < m.size() && ind >=0)
            return search(m[ind], target);
        return false;
    }


int main(){
    std::vector<std::vector<int>> m = {{23}};
        int target = 23;
    // TreeNode* root = buildTree(nodes);
    // std::cout << m.size();
    std::cout << boolalpha << searchMatrix(m, target);
    std::cout << " complete\n";
}