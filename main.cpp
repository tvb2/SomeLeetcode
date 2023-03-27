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
using namespace std;

/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith 
line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/
    
	int maxArea(vector<int>& height) {
    int maxArea= 0, area =0;
	//using multimap to sort array. Keys are heights, values are indices
	std::multimap<int,int> myMap;
	//record indices already used in calculations
	std::set<int> indices;
	for (size_t i = 0; i < height.size(); ++i){
		myMap.emplace(std::pair<int,int>(height[i], i));
	}
	auto it = myMap.rbegin();
	indices.emplace(it->second);
	for (it = std::next(it);
			 it != myMap.rend();
			  ++it){
		area = it->first * std::max( 
			abs(it->second - *indices.begin()), abs(it->second - *(--indices.end())) );
		maxArea = (area > maxArea)?area:maxArea;
		indices.emplace(it->second);
		area = 0;
		// if (it->second)
		// indices.emplace(myMap.find(height[i])->second);

	}
	return maxArea;    
    }

int main(){
	vector<int> height = {1,8,6,2,5,4,8,3,7};

	std::cout << maxArea(height) << "\n";
	

}