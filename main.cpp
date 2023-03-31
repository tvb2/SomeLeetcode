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
227. Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/


    int calculate(string s) {
        int result = 0;
        int i = 0;
        std::map<size_t, char> md;//multiply and divide
        std::map<size_t, char> pm;//plus and minus
        std::map<size_t, int> vals;//start indices of values
        for (size_t j = i; j < s.length(); ++j){
            if(s[j] >= 48 && s[j] <= 57){
                size_t k = j;
                std::string v = "";
                while (s[j] >= 48 && s[j] <= 57){
                    v += s[j];
                    ++j;
                }
                vals[k] = stoi(v);
            }
            if (s[j] == '+' || s[j] == '-')
                pm[j] = s[j];
            if (s[j] == '*' || s[j] == '/')
                md[j] = s[j];
        }
        for (auto it = md.begin(); it != md.end(); ++it){
            auto itV = std::prev(vals.lower_bound(it->first));
            if (it->second == '*')
                itV->second *= (std::next(itV))->second;
            else 
                itV->second /= (std::next(itV))->second;
            vals.erase(std::next(itV));
        }
        for (auto it = pm.begin(); it != pm.end(); ++it){
            auto itV = std::prev(vals.lower_bound(it->first));
            if (it->second == '+')
                itV->second += (std::next(itV))->second;
            else
                itV->second -= (std::next(itV))->second;
            vals.erase(std::next(itV));
        }
        return vals.begin()->second;
    }


int main(){
    // std::string s = "3+587 -100  * 3 / 2 + 4";
    // std::string s = " 3+5 / 2 "; 
    // std::string s = " 3/2 ";
     std::string s = "3+2*2";
    
    std::cout << calculate(s) << "\n";

 
}