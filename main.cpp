#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 316. Remove Duplicate Letters. Medium
/*
Given a string s, remove duplicate letters so that every letter appears once and
only once. You must make sure your result is the smallest in lexicographical
order among all possible results.
*/
string removeDuplicateLetters(string s) {
  int len = s.length();
  std::map<char, int> alpha;
  std::map<char, bool> used;
  std::vector<int> list;

  // create alphabet usage map
  for (int i = 0; i < len; ++i) {
      if (alpha.find(s[i]) == alpha.end()) {
        alpha[s[i]] = 1;
      }
      else
        ++alpha[s[i]];
      used[s[i]] = false;
    }

for (int i = 0; i < len; ++i) {
  --alpha[s[i]];
  if (used[s[i]] == true)
    continue;

  while(list.size() > 0 && s[i] < s[list.back()] && alpha[s[list.back()]] > 0){
    used[s[list.back()]] = false;
    list.erase(list.end());
  }
  list.push_back(i);
  used[s[i]] = true;
}
std::string result;
for (auto i:list){
  result.push_back(s[i]);    
}

    
    return result;
  }
  int main() {
    std::string s = "cdadabcc" ;// "bccaabb"; // "leetcode"; //"cdadabcc"
    std::cout << removeDuplicateLetters(s) << "\n";
  }