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
#include <iomanip>
using namespace std;

/*
424. Longest Repeating Character Replacement. Medium
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
 You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

    //implementing editorial solution with sliding window. See Leetcode for details
    int characterReplacement(string s, int k) {
        int result = 0;
        //if we can replace all characters in s, then k is the answer
        if (k >= s.length())
            return k;
        std::map<char, int> freq;
        int maxFreq = 0;//frequency of the character that was ever found to be maximum
        //fill up frequency map with k first characters
        for (size_t i = 0; i < s.size() && i < k; ++i){
            ++freq[s[i]];
            if (freq[s[i]] > maxFreq)
                maxFreq = freq[s[i]];
        }
        size_t l = 0, r = k;
        for (; r < s.length(); ++r){
            ++freq[s[r]];
            if (freq[s[r]] >= maxFreq){
                maxFreq = freq[s[r]];
            }
            if (r - l + 1 - maxFreq > k){
                --freq[s[l]];
                ++l;
            }
        }
        return (r - l);
    }

int main(){
    // std::string s = s = "ABAB";
    std::string s = "AABABBA";
    int  k = 1;
    std::cout << characterReplacement(s, k) << " ";

}