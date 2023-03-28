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
6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

    string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string result;
		int len = s.length();
		size_t row = 0;
		while (row < numRows){
			int pos = row;
			if (row == 0 || row == numRows - 1){
				while(pos < len){
					result += s[pos];
					pos = pos + (2*numRows - 2);
				}
				++row;
			}
			else{
				bool toggle = true;
				int temp = pos;
				while (temp < len){
					result += s[temp];
					if (toggle){
						temp = pos + (2*numRows - 2 - 2*row);
						toggle = false;
					}
					else{
						temp = pos + (2*numRows - 2);
						pos = temp;
						toggle = true;
					}
				}
				++row;
			}
		}
		return result;
    }

int main(){
	string s = "b";//3: PAHNAPLSIIGYIR 4: PINALSIGYAHRPI
	int numOfRows = 1;
	std::cout << convert(s, numOfRows) << "\n";
}