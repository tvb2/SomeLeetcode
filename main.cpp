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
using namespace std;

/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

 //recursive solution
    bool helper(vector<vector<char>>& image, int sr, int sc){
        bool found = 0;
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return 0;
        if (image[sr][sc] == '1'){
            found = 1;
            image[sr][sc] = '0';
            helper(image, (sr + 1), sc);
            helper(image, (sr - 1), sc);
            helper(image, sr, (sc + 1));
            helper(image, sr, (sc - 1));
        }
        return found;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int count = 0;
        for (size_t i = 0; i < grid.size(); ++i){
            for (size_t j = 0; j < grid[0].size(); ++j){
                count += helper(grid, i, j);
            }
        }
     return count;   
    }

int main(){
    std::vector<std::vector<char>> grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
    };
    std::cout << numIslands(grid) << "\n";

}