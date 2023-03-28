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
454. 4Sum II
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
*/

//implementing solution by abivilion and shwetanknaveen
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	int result = 0;
	std::map<int,int> oneTwoSum;

	//calculate all possible sums of nums1 and nums2 and record these sums to map
	for (auto it1:nums1){
		for (auto it2:nums2){
			++oneTwoSum[it1 + it2];
		}
	}
	//calculate all possible combinations of nums3 and nums4
	//if combination already exists in the map with opposite sign, than increment result
	for (auto it3:nums3){
		for (auto it4:nums4){
			result += oneTwoSum[-(it3 + it4)];
		}
	}
return result;
}

int main(){
	vector<int> nums1 = {-1,-1}, 
	nums2 = {-1,1}, 
	nums3 = {-1,1}, 
	nums4 = {1,-1};
	std::cout << fourSumCount(nums1, nums2, nums3, nums4) <<"\n";
}