#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
/*
392. Is Subsequence. Easy
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

*/
    bool isSubsequence(string s, string t) {
        size_t sl = s.length();
        size_t tl = t.length();
        if (sl == 0){
            return true;
        }
        if ( sl > tl){
            return false;
        }
        size_t cs = 0;
        for (size_t ct = 0; ct < tl; ++ct){
            if (cs == sl)
                return true;
            if (s[cs] == t[ct])
                ++cs;
        }
        return cs == sl;
    }


int main(){
std::string s = "";
std::string t = "";

std::cout << boolalpha << isSubsequence(s,t) << "\n";

    std::cout << " \ncomplete\n";
}