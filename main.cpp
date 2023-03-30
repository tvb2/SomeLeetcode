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
using namespace std;

/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

    int longestValidParentheses(string s) {
		//base case of zero string length
		if (s.length() == 0)
			return 0;
		std::stack<int> p;
		int i = 0;
		int max = 0, incr = 2;
		for (size_t i = 0; i < s.length(); ++i){
			if (s[i] == '('){
				p.push(0);
			}
			else{// s[i] = ')'
				if (p.empty())
					continue;
				int temp = p.top() + incr;
				p.pop();
				/*special case if there was only one element left
				p = 0 
				p = 2 (illegal, cannot have closing bracket with single non-zero element left : "())" )
				*/
				if (p.empty()){
					if (temp == incr)
						p.push(temp);
					max = (incr > max)?incr:max;
					continue;
				}
				/*
				initial setup
				1. p = 2 0 0 -> p = 2 0 temp=2
				2. p = 2 0 2 -> p = 2 0 temp=4
				3. p = 2 0   -> p = 2   temp=2
				4. p = 0 0 2 -> p = 0 0 temp=4
				5. p = 0 4   -> p = 0   temp=6
				*/
				if (temp == incr){//cases 1, 3
					if (p.top() != 0){//case 3
						temp += p.top();
						p.pop();
					}
				}
				else{//cases 2, 4, 5
					p.pop();
					/*
					2. p = 2 0 -> p = 2   temp=4
					4. p = 0 0 -> p = 0 0 temp=4
					5. p = 0   -> p = ''  temp=6
					*/
					if (!p.empty() && p.top() != 0){//case 2, 5
						temp += p.top();
						p.pop();
					}
				}
				p.push(temp);
				max = (temp > max)?temp:max;
			}
		}
		return max;
    }

int main(){
	// string s = ")()())";
	// string s ="()(())";
	// string s ="())";
	// string s =")()())";
	// string s ="(()())";
	string s =")()())()()(";
	std::cout << longestValidParentheses(s) << "\n";
}