#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <stdint.h>
using namespace std;

    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0)
			return 0;
		int result = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		size_t gd = 0, sz = 0;
		while((gd < g.size()) && (sz < s.size())){
					if (s[sz] >= g[gd]){
				++result;
				++gd;
			}
			++sz;
		}
		return result;
    }

int main(){
	vector<int> g = {1, 2}, s = {1, 2, 3};
	std::cout << findContentChildren(g, s) <<"\n";
}