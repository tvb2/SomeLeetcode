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
#include <set>
using namespace std;

/*
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
      string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        std::vector<int> n1(m), n2(n);
        //convert strings to int vectors
        size_t c = 0;
        for (int i = m - 1; i >=0; --i){
            n1[c] = num1[i] - '0';
            ++c;
        }
        c = 0;
        for (int i = n - 1; i >=0; --i){
            n2[c] = num2[i] - '0';
            ++c;
        }
        if ((n == 1 && n1[0] == 0 ) || (m == 1 && n2[0] == 0))
            return "0";
        //multiply
        std::vector<int> r(m + n);
        size_t stop = 0;
        int v1 = 0, v2 = 0, adder = 0;
        for (size_t it1 = 0; it1 < m; ++it1){
            for (size_t it2 = 0; it2 < n; ++it2){
                stop = it1 + it2;
                v1 = n1[it1] * n2[it2];
                v2 = v1 + r[stop];
                adder = v2/10;
                r[stop] = v2%10;
                if (adder){
                    stop = it1 + it2 + 1; 
                    r[stop] += adder;
                    adder = 0;
                }
            }
        }
        std::string res;
        for (size_t i = 0; i <= stop; ++i){
            res.insert(res.begin(), r[i] + '0');
        }
        return res;
    }


int main(){
    std::string num1 = "0", num2 = "9133";
    std::cout << multiply(num1, num2) << "\n";
}