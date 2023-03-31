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
224. Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.
*/
    //repeating code moved to separate function
    void process(std::stack<int> &vals, std::stack<char> &ops, int t, int &result){
    if (!vals.empty() && !ops.empty()){//if already some numbers and operations pending
                    result = (ops.top() == '+')?(vals.top() + t):(vals.top() - t);
                    vals.pop(); ops.pop();
                    vals.push(result);
                }
                else if (vals.empty() && !ops.empty()){//if there are no vals but already ops (only ops possible is '-')
                    vals.push(0-t);
                    }
                else{
                    result = t;
                    vals.push(t);
                }
    }

    int helper (string s, int &i){
        int result = 0;
        std::stack<char> ops;//operations
        std::stack<int> vals;//values
        for (; i < s.length(); ++i){
            //a number
            if(s[i] >= 48 && s[i] <= 57){
                size_t k = i;
                std::string v = "";
                while (s[i] >= 48 && s[i] <= 57){
                    v += s[i];
                    ++i;
                }
                int t = stoi(v);
                process(vals, ops, t, result);
            }
            if (s[i] == '+' || s[i] == '-')
                ops.push(s[i]);
            if (s[i] == '('){
                int t = helper(s,++i);
                process(vals, ops, t, result);
                continue;
            }
            if (s[i] == ')'){
                break;
            }
        }
        return vals.top();
    }

    int calculate(string s) {
        int i = 0, result = 0;
        result = helper(s, i);
        return result;
    }


int main(){
    // std::string s = "3+587 -100  * 3 / 2 + 4";
    // std::string s = " 3+5 / 2 "; 
    // std::string s = " 3/2 ";
    //  std::string s = "3+2*2";
    // std::string s = "(1+(4+5+2)-3)+(6+8)";
    // std::string s = "-1";
    std::string s = "-(1+2)";
    
    std::cout << calculate(s) << "\n"; 
}