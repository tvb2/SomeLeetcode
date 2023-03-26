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
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing 
the order of the remaining elements.

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/
 //implementing single-pass editorial algorithm
		int findLHS(vector<int>& nums) {
      //base case
			if (nums.size() == 1){
				return 0;
			}
			//lhs - result
			int lhs = 0, greater = 0, less = 0;
			//map key=nums[i], val = number of occurencies in nums
			std::map<int,int> myMap;

			for (size_t i = 0; i < nums.size(); ++i){
				greater = 0; less = 0;
				//increment count of occurrencies
				++myMap[nums[i]];
				//check if current val + 1 exists in the map
				if (myMap.find(nums[i] + 1) != myMap.end()){
					greater = myMap[nums[i]+1];
				}
				//check if current val -1 exists in the map
				if (myMap.find(nums[i] - 1) != myMap.end()){
					less = myMap[nums[i]-1];
				}
				//only update result if val+1 or val-1 exist
				if (greater > 0 || less > 0){
					lhs = std::max(
								{lhs, myMap[nums[i]]+greater, myMap[nums[i]] + less},
									[&](int a, int b){
										return a < b;
									});
				}
		}
		return lhs;
    }

int main(){
	vector<int> nums ={1,2,3,4};
	cout << findLHS(nums) << "\n";
	

}