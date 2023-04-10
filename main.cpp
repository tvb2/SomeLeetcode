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
394. Decode String
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

    //helper recursive functions
    std::string getString(std::string s, size_t &i){
        std::string result = "";
        std::string t = "";
        for (; i < s.size(); ){
            //s[i] is k (a number):
            if (s[i] >= 48 && s[i] <= 57){
                t = "";
                while (s[i] != '['){
                    t += s[i];
                    ++i;
                }
                ++i;
                int k = std::stoi(t); //get the number - factor for the next string
                t = getString(s, i);//get the string recursively
                for (int i = 0; i < k; ++i){//append the string k times to the answer
                    result.append(t);
                }
            }
            else if (s[i] != ']'){
                result += s[i];//get the string
                ++i;
            }
            else{
                ++i;
                return result;
            }
        }
        return result;
    }


    string decodeString(string s) {
        //min size of string with brackets is 4, i.g. "1[a]". If less -must be a string without repetitions
        if (s.size() < 4)
            return s;
        size_t i = 0;
        return getString(s, i);
    }

int main(){
     std::string s = "3[a2[c]]";
     std::cout << decodeString(s) << "\n";

}