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
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/


        //try using DP (there is a probably better way calculating the total sum of all the elements and 
        // than while iterating through nums just calculate left sum and compare it to Total - nums[i] - left = right)
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int size = nums.size();
        std::vector<int> left(size); // vector of sums of all left items
        std::vector<int> right(size); // vector of sums of all right items
        left[0] = 0; left[1] = nums[0]; //base case of first and last sums match first and last nums elements
        right[size - 1] = 0; right[size - 2] =nums[size - 1];
        for (int l = 2, r = size - 3; l < size || r >= 0; ++l, --r){
            left[l] = nums[l - 1] + left[l - 1];
            right[r] = nums[r + 1] + right[r + 1];
        }
        //if element of left and right sums match, than this is our result
        for (size_t i = 0; i < size; ++i){
            if (left[i] == right[i])
                return i;
        }
        return -1;
    }



int main(){
    // std::vector<int> nums = {1,7,3,6,5,6};
    std::vector<int> nums = {-1,-1,0,1,1,0};
    
    std::cout << pivotIndex(nums) << "\n";

}