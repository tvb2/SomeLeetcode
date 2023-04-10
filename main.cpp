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
844. Backspace String Compare. Easy
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.    
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/

    bool backspaceCompare(string s, string t) {
        std::stack<char> ss, ts;
        size_t max = std::max(s.length(), t.length());
        for (size_t i = 0; i < max; ++i){
            if (i < s.length()){
                if (s[i] == '#' && !ss.empty()){
                    ss.pop();
                }
                else{
                    ss.push(s[i]);
                }
            }
            if (i < t.length()){
                if (t[i] == '#' && !ts.empty()){
                    ts.pop();
                }
                else{
                    ts.push(s[i]);
                }
            }
        }
        while (!ss.empty() & !ts.empty()){
            if (ss.top() != ts.top())
                return false;
            ss.pop(); ts.pop();
        }
        return (ss.empty() && ts.empty());
    }

int main(){
     std::string s = "xywrrmp", t = "xywrrmu#p";
     std::cout << boolalpha << backspaceCompare(s, t) << "\n";

}