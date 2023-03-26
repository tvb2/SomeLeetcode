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
1921. Eliminate Maximum Number of Monsters
You are playing a video game where you are defending your city from a group of n monsters. 
You are given a 0-indexed integer array dist of size n, where dist[i] is the initial distance in kilometers of the ith monster from the city.

The monsters walk toward the city at a constant speed. 
The speed of each monster is given to you in an integer array speed of size n, where speed[i] is the speed of the ith monster in 
kilometers per minute.

You have a weapon that, once fully charged, can eliminate a single monster. 
However, the weapon takes one minute to charge.The weapon is fully charged at the very start.

You lose when any monster reaches your city. If a monster reaches the city at the exact moment the weapon is fully charged, 
it counts as a loss, and the game ends before you can use your weapon.

Return the maximum number of monsters that you can eliminate before you lose, or n if you can eliminate all the monsters before they reach the city.

n == dist.length == speed.length
1 <= n <= 105
1 <= dist[i], speed[i] <= 105
*/
     int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    	vector<int> time(dist.size());
		//vector time is how many minutes left until the monster will reach the town
		//zero or negative value indicates that the monster will be in town at next step
		for (size_t i = 0; i < dist.size(); ++i){
			time[i] = (dist[i]%speed[i] > 0)?(dist[i]/speed[i] +1):(dist[i]/speed[i]);
		}
		//sort array and start shooting monsters from least to most subtracting 1 at each step
		//stop if we come across negative or zero value 
		sort(time.begin(), time.end());
		int count = 1, minutes = 1;
		for (size_t i = 1; i < time.size(); ++i){
			if (time[i] - minutes <= 0){
				return count;
			}
			++count;
			++minutes;
		}
		return count;
    }

int main(){
	vector<int> dist = {5,4,3,3,3};
	vector<int> speed = {1,1,5,3,1};
	std::cout << eliminateMaximum(dist, speed) << "\n";
	

}