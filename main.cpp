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
746. Min Cost Climbing Stairs
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

int minCostClimbingStairs(vector<int>& cost) {
    size_t i = 2;
    for (; i < cost.size(); ++i){
        cost[i] += std::min(cost[i - 1], cost[i - 2]);
    }
    return std::min(cost[i - 1], cost[i - 2]);
}

int main(){
    std::vector<int> cost =  {0,0,0,0};// {0,0,0,0}; // {1};// {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};// {10,15,20};
    std::cout << minCostClimbingStairs(cost) << "\n";

}