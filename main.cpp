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
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)
        return 0;
    int size = prices.size();
    int result = 0;
    std::vector<int> min(size);
    std::vector<int> max(size);
    min[0] = prices[0]; max[size - 1] = prices[size -1];
    for (int l = 0, r = size - 2; l < size || r >= 0; ++l, --r){
        min[l] = (prices[l] < min[l - 1])?(prices[l]):min[l - 1];
        max[r] = (prices[r] > max[r + 1])?(prices[r]):max[r + 1];
    }
    for (int i = 0; i < size; ++i){
        result = (max[i] - min[i] > result)?(max[i] - min[i]):result;
    }
    return result;
}

int main(){
    std::vector<int> prices = {1};
    std::cout << maxProfit(prices) << "\n";
}