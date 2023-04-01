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
using namespace std;

/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

    vector<vector<int>> generate(int numRows) {
        //create a matrix numRows*numRows
        std::vector<std::vector<int>> pascal;

        for (size_t i = 0; i < numRows; ++i){
            //add another row
            pascal.resize(pascal.size()+1);
            //set size of the row is one item bigger than previouse
            pascal[i].resize(i + 1);
            for (size_t j = 0; j < pascal[i].size(); ++j){
                //the first and las element in each row is '1'
                if (j == 0 || j == pascal[i].size() - 1){
                    pascal[i][j] = 1;
                }
                else
                    //any other element is calculated as a sum of two elements above
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }


int main(){
    int numRows = 12;
    std::vector<std::vector<int>> pascal = generate(numRows);
    for (auto i:pascal){
        for (auto j:i){
            std::cout << j << " ";
        }
        std::cout <<"\n";
    }
}