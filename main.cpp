#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. 
All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, 
the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
*/
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size());
		map<int, int> map;
		for (size_t i = 0; i < score.size(); ++i){
			map.insert(make_pair(score[i],i));
		}
		int count = 1;
		for (auto it = map.rbegin(); it != map.rend(); ++it){
			if (count == 1){
				result[it->second] = "Gold Medal";
			}
			else if (count == 2)
				result[it->second] = "Silver Medal";
			else if (count == 3)
				result[it->second] = "Bronze Medal";
			else 
				result[it->second] = to_string(count);
			++count;
		}
		return result;
    }

int main(){
	vector<int> score = {10,7};
	vector<string> result = findRelativeRanks(score);
	for (auto i:result)
	std::cout << i << "\n";
}