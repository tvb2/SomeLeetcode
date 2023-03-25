#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

/*
You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words.
Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to 
the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. 
For example, "dacb" is an anagram of "abdc".

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
*/

//this function is from another problem at LeetCode
 bool isAnagram(string s, string t) {
        //if strings are not of equal length, they cannot be anagrams
        if (s.length() != t.length())
			return false;
        //create maps containing all letters from both words
		map<char,int> mapS, mapT;
		for (size_t i = 0; i < s.length(); ++i){
			++mapS[s[i]];
			++mapT[t[i]];
		}
        //the maps must be equal. If we come across different keys or values, these are not valid anagrams
		for (auto itS = mapS.begin(), itT = mapT.begin(); itS != mapS.end(), itT != mapT.end(); ++itS, ++itT){
			if ((itS->first != itT->first) || (itS->second != itT->second))
				return false;
		}
		return true;
 }
		//using separate function to check if two strings are anagrams, iterate through words in reverse dir
    //the version that erases words from existing array
		// vector<string> removeAnagrams(vector<string>& words) {
		// for (auto it = words.end()-1; it != words.begin(); --it){
		// 	if (isAnagram(*it, *prev(it))){
		// 		it = words.erase(it);
		// 	}
		// }
		// return words;
    // }

		//the version that uses a new array to emplace results. No improvement in speed or memory
		vector<string> removeAnagrams(vector<string>& words) {
		vector<string> result;
		for (auto it = words.end()-1; it != words.begin(); --it){
			if (!isAnagram(*it, *prev(it))){
				result.emplace(result.begin(),*it);
				// it = words.erase(it);
			}
		}
		result.emplace(result.begin(),*words.begin());
		return result;
    }

int main(){
	vector<string> words = {"abba","baba","bbaa","cd","cd"};
	vector<string> result = removeAnagrams(words);
	for (auto i:result)
	std::cout << i << "\n";
}