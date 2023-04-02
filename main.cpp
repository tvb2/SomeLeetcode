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
387. First Unique Character in a String
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
1 <= s.length <= 105
s consists of only lowercase English letters.
*/


    int firstUniqChar(string s) {
        if (s.length() == 0)
            return -1;
        std::map<char,int> ind;
        int min = s.length();
        for (int i = 0; i < s.length(); ++i){
            if (ind.find(s[i]) != ind.end()){
                ind[s[i]] = -1;
            }
            else{
                ind[s[i]] = i;
            }
        }
        for (auto i = ind.begin(); i != ind.end(); ++i){
            if (i->second != -1){
                if (i->second < min){
                    min = i->second;
                }
            }
        }
        return (min == s.length())?(-1):min;
    }



int main(){
    std::string s = "aa";
    
    std::cout << firstUniqChar(s) << "\n";

}