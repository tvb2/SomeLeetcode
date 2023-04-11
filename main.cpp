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
347. Top K Frequent Elements. Medium
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
        std::map<int, int> freq;
        std::priority_queue<int> max;
        for (size_t i = 0; i < nums.size(); ++i){
            ++freq[nums[i]];
            max.push(freq[nums[i]]);
        }
        while (k > 0){
            int m = max.top();
            for (auto it = freq.begin(); it != freq.end(); ++it){
                if (it->second == m){
                    result.emplace_back(it->first);
                    --k;
                    freq.erase(it);
                    break;
                }
            }
            max.pop();
        }
        return result;
    }

int main(){
    std::vector<int> nums = {1, 4, 8, 3, 9, 1,1,2,2,3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);
     for (auto i:result)
        std::cout << i << "\n";

}