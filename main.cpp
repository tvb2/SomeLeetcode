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
1480. Running Sum of 1d Array
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
*/


    vector<int> runningSum(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i){
            nums[i] += nums[i-1];
        }
        return nums;
    }



int main(){
    std::vector<int> nums = {3,1,2,10,1};
    
    std::vector<int> result =  runningSum(nums);
    for (auto i:result)
    std::cout << i << " " << "\n";

}