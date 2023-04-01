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
#include <stack>
#include <queue>
using namespace std;

/*
2601. Prime Subtraction Operation
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.
*/

bool isPrime(int n)
{
      // Since 0 and 1 is not
      // prime return false.
      if(n == 1 || n == 0) return false;
   
      // Run a loop from 2 to n-1
      for(int i = 2; i*i <= n; i++)
      {
        // if the number is divisible by i,
        // then n is not a prime number.
        if(n % i == 0) return false;
      }
      // Otherwise n is a prime number.
      return true;
}
    //return prime numbers below input value
    std::vector<int> primeNums(int i){
        std::vector<int> primes;
        for (int j = 1; j < i; ++j){
            if (isPrime(j))
                primes.push_back(j);
        }
        return primes;
    }

    bool primeSubOperation(vector<int>& nums) {
        std::vector<int> primes;
        for (size_t i = nums.size() - 1; i > 0; --i ){
            
            if(nums[i] <= nums[i - 1]){
              primes = primeNums(nums[i - 1]);  
              int k = nums[i - 1];
              int j = 0;
                while ((k >= nums[i]) && (j < primes.size()) && (k > 0)){
                    k = nums[i - 1];
                    k -= primes[j];
                    ++j;
                }
                nums[i - 1] = k;
                if (nums[i] <= nums[i - 1])
                    return false;
            }           
        }
        return true;
    }


int main(){
    std::vector<int> nums = {17,2};
    
    std::cout << boolalpha << primeSubOperation(nums) << "\n"; 
}