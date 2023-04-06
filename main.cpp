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
1254. Number of Closed Islands. Medium
Given a 2D grid consists of 0s (land) and 1s (water).  
An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

 //recursive solution
    bool helper(vector<vector<int>>& image, int sr, int sc, bool &found, bool &bad){
        if (sr < 1 || sr >= image.size() - 1 || sc < 1 || sc >= image[0].size() - 1){
            if (image[sr][sc] == 0){
                found = 0;
                bad = 1;
            }
            return found;
        }
        if (image[sr][sc] == 0){
            found = bad?0:1;
            image[sr][sc] = 2;
            helper(image, (sr + 1), sc, found, bad);
            helper(image, (sr - 1), sc, found, bad);
            helper(image, sr, (sc + 1), found, bad);
            helper(image, sr, (sc - 1), found, bad);
        }
        return found;
    }

    //using solution from one of previous tasks
    //using two bool flags: one to indicate that we have found a candidate for an islad
    //another one is a flag that discards the candidate if the island appears to be adjacent to one of the edges of the grid
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int count = 0;
        for (size_t i = 1; i < grid.size() - 1; ++i){
            for (size_t j = 1; j < grid[0].size() - 1; ++j){
                bool found = 0, bad = 0;
                count += helper(grid, i, j, found, bad);
            }
        }
     return count;   
    }

int main(){
    std::vector<std::vector<int>> grid = {
    {0,0,1,1,0,1,0,0,1,0},
    {1,1,0,1,1,0,1,1,1,0},
    {1,0,1,1,1,0,0,1,1,0},
    {0,1,1,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,1,1,1,0},
    {0,1,0,1,0,1,0,1,1,1},
    {1,0,1,0,1,1,0,0,0,1},
    {1,1,1,1,1,1,0,0,0,0},
    {1,1,1,0,0,1,0,1,0,1},
    {1,1,1,0,1,1,0,1,1,0}
    };
    std::cout << closedIsland(grid) << "\n";

}