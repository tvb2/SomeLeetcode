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
#include <set>
using namespace std;

/*
2131. Longest Palindrome by Concatenating Two Letter Words. Medium
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 

    /*
    Using two maps: one (m) to store each string and number of occurrencies, the second (dbl) to store strings like "gg"
    then we parse map m and increment count deleting records from the map
    int the end work with map of doubles (dbl) - add those records that divide by 4 like in the case: ("aa lc cl aa").
    also add one item in the middle for cases like "ab gg ba"
    */
    int longestPalindrome(vector<string>& words) {
        int size = words.size();
        int count = 0;
        std::map<std::string,int> m;
        std::map<std::string,int> dbl;

        std::string rev = "";
        for (size_t it = 0; it < size; ++it){
            if (words[it][0] == words[it][1])
                dbl[words[it]] += 2;
            else
                ++m[words[it]];
        }
        for (auto it = m.begin(); it != m.end();){
            rev = it->first;
            std::swap(rev[0], rev[1]);    
            if (m.find(rev) != m.end()){
                count += 4*std::min(it->second, m[rev]);
                it = m.erase(it); 
                m.erase(rev);
            }
            else{
                it = m.erase(it);
            }
            if (m.empty())
                break;
            it = m.begin();
        }
        bool middle = false;
        for (auto it = dbl.begin(); it != dbl.end(); ++it){
            if (!middle && it->second%4 != 0){
                count += 2;
                it->second -= 2;
                middle = true;
            }
                count += 4*(it->second/4);
            }
        return count;
    }


int main(){
std::vector<std::string> words = {"ll","lb","bb","bx","xx","lx","xx","lx","ll","xb","bx","lb","bb","lb","bl","bb","bx","xl","lb","xx"};
std::cout << longestPalindrome(words) <<  "\n";
}