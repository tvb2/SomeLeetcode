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
409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/

int longestPalindrome(string s) {
    if (s.length() == 0)
        return 0;
    if (s.length() == 1)
        return 1;
    int result = 0;
    std::map<char, int> alpha;
    for (size_t i = 0; i < s.length(); ++i){
        ++alpha[s[i]];
    }
    bool plusOne = false;
    for (auto it = alpha.begin(); it != alpha.end(); ++it){
        if (it->second > 1){
            result += it->second/2*2;
        }
        if (it->second%2 == 1 && result%2 == 0)
                ++result;
    }
    return result;
}

int main(){
    std::string s = "ccc";
    // std::string s = "a";
    std::cout << longestPalindrome(s) << "\n";
}