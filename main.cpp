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
62. Unique Paths. Medium
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
1 <= m, n <= 100
*/

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> field(m);
    //initialize the field with ones (basic case for row 1 and colum 1)
    for (auto &i:field)
        i.resize(n, 1);
    //number of combinations for other cells is sum of [i-1][j] and [i][j-1]
    for (size_t i = 1; i < field.size(); ++i){
        for (size_t j = 1; j < field[i].size(); ++j){
            field[i][j] = field[i - 1][j] + field[i][j - 1];
        }
    }
 return field[m - 1][n - 1];   
}

int main(){
    int m = 5, n = 5;
     std::cout << uniquePaths(m, n) << "\n";

}