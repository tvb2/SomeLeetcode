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
1046. Last Stone Weight. Easy
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

    int lastStoneWeight(vector<int>& stones) {
        //base case
        if (stones.size() == 1)
            return stones[0];
        std::priority_queue<int> q{stones.begin(), stones.end()};
        int temp1 = 0, temp2 = 0;
        while (q.size() > 1){
            temp1 = q.top(); q.pop();
            temp2 = q.top(); q.pop();
            if (temp1 == temp2)
                continue;
            temp1 = (temp1 < temp2)?(temp2 - temp1):(temp1 - temp2);
            q.push(temp1);
        }
        return (q.size() == 1)?q.top():0;
    }

int main(){
     std::vector<int> stones = {2,7,4,1,8,1};
     std::cout << lastStoneWeight(stones) << "\n";

}