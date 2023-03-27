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
81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array 
is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated 
at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

	bool binarySearch(vector<int>& nums, int target, int l, int r){
		int ind = l + (r - l)/2;
		while ( l >=0 && r < nums.size() && l <= r){
			ind = l + (r - l)/2;
			if (nums[ind] == target){
				return true;
			}
			if (nums[ind] > target){
					r = ind - 1;
					while ( (r >= l) && (nums[r] == nums[ind]) )
						--r;
				}
				else{
					l = ind +1;
					while ( (l <= r) && (nums[l] == nums[ind]) )
						++l;
				}
		}
		return false;
	}

    bool search(vector<int>& nums, int target) {
		if ((nums.size() == 1) && nums[0] == target)
			return true;
		
		int l = 0, r = nums.size() - 1, ind = l;
		while (l <= r){
			ind = l+ (r - l)/2;			
			//rotated
			if (nums[ind] == target)
				return true;
			
			if (nums[l] == nums[r]){
				if (nums[l] == target)
					return true;
				++l; --r;
				continue;
			}
			if (nums[ind] >= nums[l]){
				if ( (nums[ind] > target) && (target >= nums[l]) ) {
					return binarySearch(nums, target, l, ind - 1);
				}
				else{
						l = ind +1;
						while ( (l <= r) && (nums[l] == nums[ind]) )
							++l;
				}
			}
			else if ( nums[ind] <= nums[r]){// we are in the lower side of the array
				if ( (nums[ind] < target) && (target <= nums[r])) {// target is between ind and r
					return binarySearch(nums, target, ind + 1, r);
				}
				else{
					r = ind - 1;
					while ( (r >= l) && (nums[r] == nums[ind]) )
						--r;
				}
			}
		}
		return false;
    }

int main(){
	vector<int> nums = {3,4,4,4,4,4,4,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,10,10,10,-10,-10,-10,-9,-8,
	-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-1,-1,0,0,0,1,1,1,1,1,1,2,2,
	2,2,2,2,2,2,3,3,3};
	int target = 2;
	std::cout << boolalpha << search(nums, target) << "\n";
	

}