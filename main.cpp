#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h> 
#include <wchar.h>
#include <cstring>
using namespace std;
// 1877. Minimize Maximum Pair Sum in Array
/*
The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

Each element of nums is in exactly one pair, and
The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.

Constraints:

n == nums.length
2 <= n <= 105
n is even.
1 <= nums[i] <= 105
*/

    int minPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int l = 0, r = nums.size() - 1, sum = 0;
      while (l < r){
        sum = (nums[l] + nums[r] > sum)?(nums[l] + nums[r]):sum;
        ++l; --r;
      }
      return sum;        
    }

  int main() {
    std::vector<int> nums ={3,5,2,3};// {3,5,4,2,4,6};
    std::cout << minPairSum(nums) << "\n";

    std::cout << "completed\n";
  }