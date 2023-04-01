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
150. Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1)
            return std::stoi(tokens[0]);
        int result = 0, first = 0, second = 0;
        std::stack<int> s;
        for (size_t i = 0; i < tokens.size(); ++i){
            if (tokens[i] == "+" ||  tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
                    second = s.top(); s.pop();
                    first = s.top(); s.pop();
                if (tokens[i] == "+"){
                    s.push(first + second);
                }
                else if (tokens[i] == "-"){
                    s.push(first - second);
                }
                else if (tokens[i] == "/" ){
                    s.push(first / second);
                }
                else{// '*'
                    s.push(first * second);
                }
            }
            else{//a valid signed or unsigned integer
                s.push(std::stoi(tokens[i]));
            }
        }
        return s.top();
    }


int main(){
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // std::cout << std::stoi("-100") << "\n";
    
    std::cout << evalRPN(tokens) << "\n";

}