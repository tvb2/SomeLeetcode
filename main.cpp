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
using namespace std;

/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/
    //editorial brute force
    //     int trap(vector<int>& height) {
    //     int ans = 0;
    //     int size = height.size();
    //     for (int i = 1; i < size - 1; i++) {
    //         int left_max = 0, right_max = 0;
    //         for (int j = i; j >= 0; j--) { //Search the left part for max bar size
    //             left_max = max(left_max, height[j]);
    //         }
    //         for (int j = i; j < size; j++) { //Search the right part for max bar size
    //             right_max = max(right_max, height[j]);
    //         }
    //         ans += min(left_max, right_max) - height[i];
    //     }
    //     return ans;
    // }

    //editorial dynamic programming
    // int trap(vector<int>& height)
    // {
    //     if(height.empty())
    //         return 0;
    //     int ans = 0;
    //     int size = height.size();
    //     vector<int> left_max(size), right_max(size);
    //     left_max[0] = height[0];
    //     for (int i = 1; i < size; i++) {
    //         left_max[i] = max(height[i], left_max[i - 1]);
    //     }
    //     right_max[size - 1] = height[size - 1];
    //     for (int i = size - 2; i >= 0; i--) {
    //         right_max[i] = max(height[i], right_max[i + 1]);
    //     }
    //     for (int i = 1; i < size - 1; i++) {
    //         ans += min(left_max[i], right_max[i]) - height[i];
    //     }
    //     return ans;
    // }

    //editorial stack
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st; //indices
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }



int main(){
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    std::cout << trap(height) << "\n";

}