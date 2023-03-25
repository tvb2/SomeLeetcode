#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

/*
561. Given an integer array nums of 2n integers, group these integers into n pairs 
(a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. 
Return the maximized sum.

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
*/
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int sum = 0;
		int it = nums.size()-2;
		while(it >= 0){
			sum += nums[it];
			it -= 2; 
		}
		return sum;
    }

int main(){
	vector<int> nums ={6,2,6,5,1,2};
	cout << arrayPairSum(nums) << "\n";
	

}