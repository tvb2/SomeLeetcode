#include <iostream>

#include <vector>
#include <set>
#include <queue>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/*
994. Rotting Oranges. Medium
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
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
*/

/*
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
*/
    /**
     * convert string to a vector of Nodes for level-order creation
     * Each element of vector represents a level in the tree
    */
/*
    std::vector<std::vector<TreeNode*>> getNodesVector(std::string nodes){
        std::vector<std::vector<TreeNode*>> nVect;
        std::string temp;
        for (auto it = nodes.begin(); it != nodes.end(); ++it){
            if (*it == ' ')
                it = nodes.erase(it);
        }
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
//using quee to add rotten oranges iterate the grid layer by layer
      int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, time = 0;
        std::queue<std::pair<int, int>> r;
        
        //first parse the matrix to record coordinates of rotten oranges and total number of fresh oranges
        for (int row = 0; row < grid.size(); ++row){
            for (int col = 0; col < grid[0].size(); ++col){
                if (grid[row][col] == 2){//rotten orange
                    r.push(std::pair<int,int>(row,col));//coordinates of initially rotten orange
                }
                else if (grid[row][col] == 1){
                    ++fresh;//count of fresh oranges
                }
            }
        }
        //number of rotten oranges
        int size = r.size();
        while (!r.empty() && fresh > 0){
            ++time;//we iterate time only once per layer
            //start layer - infect all oranges that surround rotten ones
            for (int n = 1; n <= size; ++n){
                int row = r.front().first, col = r.front().second;
                //list of all possible neighbours
                std::vector<std::vector<int>> neighbours = {{row + 1, col}, {row, col + 1}, {row - 1, col}, {row, col - 1}};
                for (size_t it = 0; it < neighbours.size(); ++it){
                    int x = neighbours[it][0], y = neighbours[it][1];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()){
                        if (grid[x][y] == 0 || grid[x][y] == 2)
                            continue;
                        if (grid[x][y] == 1){
                            grid[x][y] = 2;
                            --fresh;
                            if (fresh > 0) r.push(std::pair<int,int>(x,y));
                        }
                    }
                }
                r.pop();//remove the orange from list since we have iterated all its neighbours
            }
            size = r.size(); //update number of oranges that yet have to be iterated
        }
        return (fresh == 0)?time:-1;
    }

int main(){
    std::vector<std::vector<int>> grid = {//58
        {2,0,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,0,1},
        {1,0,1,0,1,0,0,1,0,1},
        {1,0,1,0,1,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}    
        };
    // std::vector<std::vector<int>> grid = {//-1
    //     {1,2,0,1},
    //     {1,1,0,0},
    //     {1,1,1,1},
    //     {1,2,1,1}
    // };
    // std::vector<std::vector<int>> grid = {//3
    //     {1,2,1,1},
    //     {1,1,1,1},
    //     {1,1,1,1},
    //     {1,2,1,1}
    // };
    // std::vector<std::vector<int>> grid = {//4
    //     {2,1,1},
    //     {1,1,0},
    //     {0,1,1}
    // };

    // TreeNode* root = buildTree(nodes);
    std::cout << orangesRotting(grid) << "\n";
    std::cout << " complete\n";
}