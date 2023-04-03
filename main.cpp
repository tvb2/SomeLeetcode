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
392. Is Subsequence
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
*/

    //searching t for symbols from s starting at the position of previousely found symbol
    bool isSubsequence(string s, string t) {
        size_t it = 0, j = 0; // indices of t to search for symbols from s
        for (size_t i = 0; i < s.size(); ++i){//if there is no occurrence of s[i] in t from pos=it to the end of the string, return false
            j = t.find_first_of(s[i], it); 
            if (j == std::string::npos)
                return false;
            it = j+1;
        }
        return true;
    }



int main(){
    std::string s = "axc", t = "ahbgdc";
    std::cout<< boolalpha << isSubsequence(s, t) << "\n";

}