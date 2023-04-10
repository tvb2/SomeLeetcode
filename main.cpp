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
<<<<<<< HEAD
299. Bulls and Cows
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.
*/

    /*using two freq maps s and g for secret and guess;
    than compare each symbol fo secret with same position in guess
    if they are the same, increment bulls
    if they are not the same, increment freq of secret[i] in s and guess[i] in g
    finally, cows is a total sum of min of s[i] and g[i]
    */
    string getHint(string secret, string guess) {
        std::string result = "";
        std::map<int, int> s{{0,0}, {1,0}, {2,0}, {3, 0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}}, g = s;
        int bulls{0}, cows{0};
        bulls = 0; cows = 0;
        for (size_t i = 0; i < secret.length(); ++i){
            if (secret[i] == guess[i]){
                ++bulls;
            }
            else{
                ++s[secret[i]];
                ++g[guess[i]];
            }
=======
63. Unique Paths II. Medium
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/
    //refer to UniquePath problem for basic solution without an obstacle
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    for (auto &i:obstacleGrid)
        for (auto &j:i){
            j = (j == 1)?(-1):j;
        }
    //initialize the obstacleGrid with ones (basic case for row 1 and colum 1)
    int i = 0, j = 1;
    bool obstacle = false;
    for (; i < m; ++i){
        obstacle = obstacle || (obstacleGrid[i][0] == -1);
        if (obstacle && obstacleGrid[i][0] == -1)
            obstacleGrid[i][0] =  0;
        if (!obstacle)
            obstacleGrid[i][0] =  1;
    }
    obstacle = false;
    for ( ; j < n; ++j){
        obstacle = obstacle || (obstacleGrid[0][j] == -1);
        if (obstacle && obstacleGrid[0][j] == -1){
            obstacleGrid[0][j] = 0;
        }
        if (!obstacle)
            obstacleGrid[0][j] = 1;
    }
    for (size_t i = 1; i < obstacleGrid.size(); ++i){
        for (size_t j = 1; j < obstacleGrid[i].size(); ++j){
            if (obstacleGrid[i][j] == -1){
                obstacleGrid[i][j] = 0;
                continue;
            }
            obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
>>>>>>> uniquePaths
        }
        for (size_t i = 0; i < s.size(); ++i){
            cows += std::min(s[i], g[i]);
        }
        result = std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';
    return result;
    }
<<<<<<< HEAD

int main(){
     std::string secret = "2222", guess = "0000";
     std::cout << getHint(secret, guess) << "\n";
=======
    return obstacleGrid[m - 1][n - 1];   
}

int main(){
    std::vector<std::vector<int>> obstacleGrid = 
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    /*
    {
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {1},
        {1},
        {0},
        {1},
        {0},
        {0},
        {1},
        {0},
        {0},
        {0},
        {0},
        {1}
    };
    */
    int m = 5, n = 5;
     std::cout << uniquePathsWithObstacles(obstacleGrid) << "\n";
>>>>>>> uniquePaths

}