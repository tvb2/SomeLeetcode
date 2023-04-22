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
621. Task Scheduler. Medium
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 

    //solution by beetlecamera with my explanation
    int leastInterval(vector<char>& tasks, int n) {
        //frequency map of characters
        std::map<char, int> m;
        int max = 0;//max frequency element
        for (auto it = tasks.begin(); it != tasks.end(); ++it){
            ++m[*it];
            max = std::max(max, m[*it]);//record max freq element
        }
        int res = (max - 1)*(n + 1);//possible number of operations is a rectangle of this size
        for (auto i:m)
            if (i.second == max) 
                ++res;//add each element that is equal to maximum frequency
        return std::max(res,static_cast<int>(tasks.size()));//choose maximum of possible result and length of tasks array
    }

int main(){
// std::vector<char> tasks = {'A','A','A','B','B','B'}; 
// std::vector<char> tasks = {'A','B','C','D','E','A','B','C','D','E'};
// std::vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
std::vector<char> tasks = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
int n = 2;
std::cout << leastInterval(tasks, n) <<  "\n";
}