#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 1930. Unique Length-3 Palindromic Subsequences
/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.
*/

  int countPalindromicSubsequence(string s) {
    std::vector<int> alpha(26,0);
    std::vector<bool> used(26,false);
    std::vector<char> list;

    //create a map of characters and dictionaries for each one
    std::map<char, std::vector<int>> m;
    for (char c = 'a'; c <= 'z'; ++c){
      m[c] = alpha;
    }
    
    //create dictionary with number of occurrencies of each character
    for (auto i = 0; i < s.length(); ++i){
      ++alpha[s[i] - 'a'];
    }

    int count = 0;

    //main logic
    for (auto i = 0; i < s.length(); ++i){
      int pos = s[i] - 'a';
      --alpha[pos];

      //check for all candidates that current character makes a palindro
      for(auto j = 0; j < list.size(); ++j){
        if (m[list[j]][pos] == 0 && !(alpha[pos] == 0 && s[i] == list[j])){
          m[list[j]][pos] = 1;
          ++count;
        }
      }
      //check if character is already candidate for checking. If not and it qualifies - make it candidate
      if (alpha[pos] != 0 && !used[pos]){
        used[pos] = true;
        list.push_back(s[i]);
      }
      if (alpha[pos] == 0 && used[pos]){
        int k = 0;
        while(list[k] != s[i])
          ++k;
        list.erase(list.begin() + k);
      }

    }
    return count;
  }

  int main() {
    std::string s = "adc";//"aabca";// "bbcbaba";
    std::cout << countPalindromicSubsequence(s) << "\n";

    std::cout << "completed\n";
  }