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
733. Flood Fill. Easy
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/


    //recursive solution
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int current){
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if (image[sr][sc] == current){
            image[sr][sc] = color;
            helper(image, (sr + 1), sc, color, current);
            helper(image, (sr - 1), sc, color, current);
            helper(image, sr, (sc + 1), color, current);
            helper(image, sr, (sc - 1), color, current);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int current = image[sr][sc];
        helper(image, sr, sc, color, current);
        return image;
    }

int main(){
    std::vector<std::vector<int>> image = {
        {0,0,0},
        {0,0,0},
        // {1,0,1}
    }; 
    int  sr = 0, sc = 0, color = 2;
    std::vector<std::vector<int>> result = floodFill(image, sr, sc, color);
    for (auto i:result){
        for (auto j:i){
            std::cout<< j <<" ";
        }
        std::cout << "\n";
    }

}