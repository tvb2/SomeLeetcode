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
33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

	int binarySearch(vector<int>& nums, int target, int l, int r){
		int ind = l + (r - l)/2;
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

    int search(vector<int>& nums, int target) {
		if ((nums.size() == 1) && nums[0] == target)
			return 0;
		int l = 0, r = nums.size() - 1, ind = l;
		
		while (l <= r){
			ind = l+ (r - l)/2;
			
			//not rotated
			if (nums[l] < nums[r])
				return binarySearch(nums, target, l, r);
			
			//rotated
			if (nums[ind] == target)
				return ind;
			
			
			if (nums[ind] >= nums[l]){//we are in the higher side of the array
				if ( (nums[ind] > target) && (target >= nums[l])) {//target is between l and ind;
					return binarySearch(nums, target, l, ind - 1);
				}
				else
					l = ind +1;
			}
			else if ( nums[ind] <= nums[r]){// we are in the lower side of the array
				if ( (nums[ind] < target) && (target <= nums[r])) {// target is between ind and r
					return binarySearch(nums, target, ind + 1, r);
				}
				else
					r = ind - 1;
			}
		}
		return -1;
    }

int main(){
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;
	std::cout << search(nums, target) << "\n";
	

}