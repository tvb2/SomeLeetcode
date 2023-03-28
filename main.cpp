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
using namespace std;

/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

	std::map<int, std::vector<string>> chars{
		{2, {"a", "b", "c"}},
		{3, {"d", "e", "f"}},
		{4, {"g", "h", "i"}},
		{5, {"j", "k", "l"}},
		{6, {"m", "n", "o"}},
		{7, {"p", "q", "r", "s"}},
		{8, {"t", "u", "v"}},
		{9, {"w", "x", "y", "z"}}
		};

	//  {'a', 'b', 'c'};
    vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.length() == 0)
			return result;
		//taking first number and making combination with the rest of numbers
		//taking the rest of digits and recursively perform combinations search
		int d = digits[0] - '0';
		vector<string> temp;
		string newDig = digits.substr(1,digits.length() - 1); 
		if(digits.length() > 1){
			temp = letterCombinations(newDig);
		}
		if (digits.length() ==1 ){
			for (auto i:chars[d])
				result.emplace_back(i);
		}
		else{
			for (auto i:chars[d]){
				for (auto j:temp){
					
					result.emplace_back(i+j);
				}
			}
		}
		return result;
    }

int main(){
	string digits = "234";
	vector<string> result =  letterCombinations(digits);
	for (auto i:result)
	std::cout << i << "\n";
}