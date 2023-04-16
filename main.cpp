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
54. Spiral Matrix. Medium
Given an m x n matrix, return all elements of the matrix in spiral order.
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int size =  m * n;
        std::vector<int> res;
        int rmin = 0, rmax = m - 1;
        int cmin = 0, cmax = n - 1;
        while(size > 0){
            for (size_t col = cmin; col <= cmax; ++col){
                res.emplace_back(matrix[rmin][col]);
                --size;
            }
            ++rmin;
            if (size <= 0)
                break;
            for (size_t row = rmin; row <= rmax; ++row){
                res.emplace_back(matrix[row][cmax]);
                --size;
            }
            --cmax;
            if (size <= 0)
                break;
            for (int col = cmax; col >= cmin; --col){
                res.emplace_back(matrix[rmax][col]);
                --size;
            }
            --rmax;
            if (size <= 0)
                break;
            for (size_t row = rmax; row >= rmin; --row){
                res.emplace_back(matrix[row][cmin]);
                --size;
            }
            ++cmin;
        }
        return res;
    }


int main(){
std::vector<std::vector<int>> matrix = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
};
std::vector<int> res = spiralOrder(matrix);
for (auto it:res)
    std::cout << it << " ";
}