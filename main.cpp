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
using namespace std;

/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{-1,-1};
		//base case
		if (nums.size() == 0)
			return result;
		if ((nums.size() == 1)){
			if(nums[0] == target){
				result[0] = 0; result[1] = 0;
			}
			return result;
		}
		
		int l = 0, r = nums.size() -1;
		

		while (l <= r){
			int ind = l + (r - l)/2;
			//case when l and r values are both our target values
			if (nums[l] == target){
				while ( (l >= 0) && (nums[l] == target) ){
					--l;
					if (l < 0){
						break;
					}
				}
				result[0] = l + 1;
				l = (l >= 0)?l:0;
			}
			if (nums[r] == target){
				while ( (r < nums.size()) && (nums[r] == target) ){
					++r;
					if (r > nums.size() - 1)
						break;
				}	
				result[1] = r - 1;
				r = (r < nums.size())?(r):(nums.size() -1);
			}

			//solution found and is not empty
			if (result[0] != -1 && result[1] != -1)
				return result;

			//binary search using middle index
			if (nums[ind] == target){
				l = ind; r = ind;
			}
			if (nums[ind] < target){
				l = ind + 1;
				while ( l <= r && nums[l] == nums[ind]){
					++l;
				}
			}
			if (nums[ind] > target){
				r = ind - 1;
				while (l <= r && nums[r] == nums[ind]){
					--r;
				}
			}
		}
		return result;
	}

int main(){
	vector<int> nums = {1,2,2};
	int target = 2;
	vector<int> result = searchRange(nums, target);
	for (auto i:result)
	std::cout << i << " ";
	

}