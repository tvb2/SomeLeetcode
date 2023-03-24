#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
using namespace std;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
		if (nums.size() < 4)
			return result;
		sort(nums.begin(), nums.end());
		int64_t sum = 0;
		vector<int>t;
		for (size_t i = 0; i < nums.size() - 3; ++i){
			if (i > 0 && nums[i] == nums[i - 1])
					continue;
			for (size_t l = i+1; l < nums.size() - 2; ++l){
				while ( (l-i >=2) && nums[l] == nums[l-1] && l < nums.size() - 2)
					++l;
				size_t m = l+1, r = nums.size() - 1;
				while (m < r){
					sum =static_cast<int64_t>(nums[i]) + static_cast<int64_t>(nums[l]) + static_cast<int64_t>(nums[m]) + static_cast<int64_t>(nums[r]);
					if (sum == target){
						t = {nums[i], nums[l], nums[m], nums[r]};
						result.emplace_back(t);
						++m; --r;
					}
					if (sum < target)
						++m;
					if (sum > target)
						--r;
					while((m - l >= 2) && (nums[m] == nums[m-1]) && (m < r))
						++m;
					while((r <= nums.size() - 2) && (nums[r] == nums[r+1]) && (r > m))
						--r;
				}
			}
		}
		return result;
    }

int main(){
	vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
	int target = -1;
	vector<vector<int>> result =  fourSum(nums, target);
	for (auto i:result){
		for (auto j:i)
			std::cout << j << " ";
		std::cout <<"\n";
	}

}