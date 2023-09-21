#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

//1337. The K Weakest Rows in a Matrix
/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.   
Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
*/
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int zeroes = 0;
        std::map<int, std::vector<int>> count;
        std::vector<int> result;
        for (size_t i = 0; i < m; ++i){
            int local = 0;
            for (int j = n - 1; j >= 0; --j){
                if (mat[i][j] == 0){
                    ++local;
                }
                else{
                    break;
                }
            }
            count[n-local].emplace_back(i);
        }            
        auto it = count.begin();
        while (k != 0 && it != count.end()){
            for (size_t i = 0; i < it->second.size(); ++i){
                if (k <= 0)
                    break;
                result.emplace_back(it->second[i]);
                --k;
            }
            ++it;
        }
        return result;
    }


int main(){
    std::vector<std::vector<int>> v = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}
        };
    int k = 3;

    std::vector<int> result = kWeakestRows(v, k);
    for (size_t i = 0; i < result.size(); ++i){
        std::cout << result[i] << " ";
    }
    std::cout << " \ncomplete\n";
}