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
704. Binary Search
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, ind = l;
    ind = l + (r - l)/2;
    while ( l >=0 && r < nums.size() && l <= r){
        ind = l + (r - l)/2;
        if (nums[ind] == target){
            return ind;
        }
        if (nums[ind] > target){
            r = ind -1;
        }
        else {
            l = ind +1;
        }
    }
    return -1;
}

int main(){
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    std::cout << search(nums, target);
}