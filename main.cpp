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
692. Top K Frequent Words. Medium
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
*/

    vector<string> topKFrequent(vector<string>& words, int k) {
        std::vector<string> result;
        std::map<std::string, int> q;//frequency map of all words
        std::priority_queue<int> max;//priority quee will store frequencies of the words in descending order
        
        //fill up the map and frequncies in the descending order
        for (auto it = words.begin(); it != words.end(); ++it){
            ++q[*it];
            max.push(q[*it]);
        }

        //picking highest frequencies first find corresponding words in the map (where they are already sorted lexicographically)
        while (k > 0){
            int m = max.top();
            for (auto it = q.begin(); it != q.end(); ++it){
                if (it->second == m){
                    result.emplace_back(it->first);
                    --k;
                    q.erase(it); //need to erase found word to prevent re-using it if the frequency of the next word is the same
                    break;
                }
            }
            max.pop();
        }
        return result;
    }

int main(){
    //  std::vector<std::string> words = {"i","love","leetcode","i","love","coding"};
     std::vector<std::string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
     int k = 4;
     std::vector<std::string> result = topKFrequent(words, k);
     for (auto i:result)
        std::cout << i << "\n";

}