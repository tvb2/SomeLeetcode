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
// 1980. Find Unique Binary String
/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n 
that does not appear in nums. If there are multiple answers, you may return any of them.

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/

// function to convert string representing binary value to decimal
int convert(std::string s) {
  //have to do this down below because had issues converting long strings (big numbers) to long long
  char * cstr = new char [s.length()+1];
  std::strcpy (cstr, s.c_str());
  char * pEnd;
  long long n = strtol(cstr,&pEnd,10); 
	int dec = 0, i = 0, rem;

	while (n != 0) {
		rem = n % 10;
		n /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}

// function to convert decimal to binary 
std::string decToBinary(int n) 
{ 
  std::string result;
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 

        // storing remainder in binary array 
        int c = n % 2;
        result = std::to_string(c) + result; 
        n = n / 2; 
        i++; 
    }
    if (result == "")
      result = "0";
    return result;
} 

string findDifferentBinaryString(vector<string>& nums) {
  //expected maximum number of combinations is 2^n
  //the task is to construct all possible combinations and return the first one which is missing in nums
  //for n = 16 there are 65 536 combinations possible
  //another approach takes into account that each combination can be represented as a decimal number up to 2^n
  //converting each string into a decimal number and knowing maximum possible for current n we can easily identify missing
  //elements
  std::string result;
  std::set<int> dec;
  std::vector<int> decimals;
  for (auto i = 0; i < nums.size(); ++i){
    dec.emplace(convert(nums[i]));
    decimals.push_back(convert(nums[i]));
  }
  long long max = pow(2,nums.size());
  int val = 0;
  for (int i = 0; i < max; ++i){
    if (dec.find(i) == dec.end()){
      val = i;
      break;
    }
  }
  result = decToBinary(val);
  while (result.length() < nums.size()){
    result.insert(result.begin(),'0');
  }
  return result;    
}

  int main() {
    std::vector<std::string> nums ={"11010011101","10110010101","01011001111","01100011001","00110110110","10110011011","11110000010","01110000000","00110011100","11111011100","11111110110"};// {"011", "001", "000"};
    std::cout << findDifferentBinaryString(nums) << "\n";

    std::cout << "completed\n";
  }