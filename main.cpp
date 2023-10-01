#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
// 557. Reverse Words in a String III. Easy
/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial 
word order.
Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

string reverseWords(string s) {
  int len = s.length();
  std::string::iterator l = s.begin();
  for (int i = 1; i < len; ++i){
    if (s[i] != ' '){
      l = s.insert(l,s[i]);
      s.erase(l+i);
    }
  }
    return s.substr(0,len);
}
int main() {
  std::string s = "Let's take LeetCode contest";
  std::cout << reverseWords(s) << "\n";
}