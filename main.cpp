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
278. First Bad Version
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API.
1 <= bad <= n <= 2^31 - 1
*/
    
    int bad = 2;
    // The API isBadVersion is defined for you.
    bool isBadVersion(int version){ return version >= bad;}

    //using binary search to identify the first bad version
    int firstBadVersion(int n) {
        if (n == 1)
            return n;
        int l = 1, r = n, t = n;
        while (l < r){
            t = l + (r-l)/2;
            if (!isBadVersion(t))
                l = t+1;
            else
                r = t;
        }
        return (l==r)?l:t;
    }


int main(){
    int n = 2;
    std::cout << firstBadVersion(n);
}