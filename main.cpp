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
27. Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/
    
	    int removeElement(vector<int>& nums, int val) {
			if (nums.size() == 0)
				return 0;
			int ith = 0;
			for (size_t i = 0; i < nums.size(); ++i){
				if (nums[i] != val){
					nums[ith] = nums[i];
					++ith;
				}
			}
        return ith;
    }

int main(){
	vector<int> nums = {2,3};
	int val = 2;

	std::cout << removeElement(nums, val) << "\n";
	

}