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
1706. Where Will the Ball Fall. Medium
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is 1 or -1.
*/

    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> res(n);
        if (grid.size() == 1 && grid[0].size() == 1){
            res[0] = -1;
            return res;
        }
        int row = 0, col = 0;
        for (int i = 0; i < res.size(); ++i){
            row = 0, col = i;
            bool through = true;
            while (row < m){
                if ((col == 0 || grid[row][col - 1] == 1) && grid[row][col] == -1){
                    res[i] = -1;
                    through = false;
                    break;
                }
                if ((col == (n-1) || grid[row][col + 1] == -1) && grid[row][col] == 1){
                    res[i] = -1;
                    through = false;
                    break;
                }
                if (grid[row][col] == 1){
                    ++row; ++col;
                    continue;
                }
                if (grid[row][col] == -1){
                    ++row; --col;
                    continue;
                }
            }
            if (through)
                res[i] = col;
        }
        return res;
    }


int main(){
// std::vector<std::vector<int>> grid = {
//     {1}
// };
std::vector<std::vector<int>> grid = {
{-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,-1}
};
std::vector<int> res = findBall(grid);
for (auto it:res)
    std::cout << it << " ";
}