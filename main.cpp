#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
using namespace std;

/**
 Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.

Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.

Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.

Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. 
Change the sign as necessary (from step 2).

If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. 
Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits. 	
Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
 */

    int myAtoi(string s) {
		if (s.length() == 0)
			return 0;
		long long result = 0;
		bool signSet = false, spaces = true;
		int sign = 1;
		for (size_t i = 0; i < s.length(); ++i){
			//remove leading spaces (could be a function)
			while(spaces && (s[i] == ' ') && (i < s.length()))
				++i;
			spaces = false;

			//could be a function
			//immediately after removing leading zeroes check for sign
			//if character is '-', '+' or a digit - set sign accordingly
			if (!signSet && 
				(s[i] == '-' || 
					s[i] == '+' || 
						(s[i] >= 48 && s[i] <= 57) )){
				sign = (s[i] == '-')?(-1):1;
				signSet = true;
				//if the character wasn't a digit - increment i and proceed parsing string
				if (s[i] == '-' || s[i] == '+')
					continue;
			}
			//if not one of the above was read - return zero
			else if (!signSet)
				return 0;

			//once we have removed leading spaces, took care of sign, 
			//if we come across char that should not be there, return what's contained so far
			if ( (s[i] < 48) || (s[i] > 57))
				break;
			// uint64_t t = static_cast<uint64_t>(sign*(result*10 + s[i] - 48));
			long long t = sign*(result*10);
			// int64_t t1 = numeric_limits<int>::min();
			if ((sign < 0) && (t < (static_cast<long long>INT_MIN + static_cast<long long>(s[i] - 48)))){
				// (static_cast<uint64_t>(sign*(result*10 + s[i] - 48)) < numeric_limits<int>::min()))
				return numeric_limits<int>::min();
			}
			else if (sign > 0 && static_cast<uint64_t>(result*10 + s[i] - 48) > numeric_limits<int>::max())
				return numeric_limits<int>::max();
			else
				result = result*10 + s[i] - 48;
		}
		return result*sign;
    }

int main(){
	// string s = "42";// "-000000000000001";
	string s = "-000000000000001";
	std::cout << myAtoi(s) <<"\n";
}