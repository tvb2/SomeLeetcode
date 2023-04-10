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
299. Bulls and Cows
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.
*/

    /*using two freq maps s and g for secret and guess;
    than compare each symbol fo secret with same position in guess
    if they are the same, increment bulls
    if they are not the same, increment freq of secret[i] in s and guess[i] in g
    finally, cows is a total sum of min of s[i] and g[i]
    */
    string getHint(string secret, string guess) {
        std::string result = "";
        std::map<int, int> s{{0,0}, {1,0}, {2,0}, {3, 0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}}, g = s;
        int bulls{0}, cows{0};
        bulls = 0; cows = 0;
        for (size_t i = 0; i < secret.length(); ++i){
            if (secret[i] == guess[i]){
                ++bulls;
            }
            else{
                ++s[secret[i]];
                ++g[guess[i]];
            }
        }
        for (size_t i = 0; i < s.size(); ++i){
            cows += std::min(s[i], g[i]);
        }
        result = std::to_string(bulls) + 'A' + std::to_string(cows) + 'B';
    return result;
    }

int main(){
     std::string secret = "2222", guess = "0000";
     std::cout << getHint(secret, guess) << "\n";

}