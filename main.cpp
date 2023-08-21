#include <iostream>

#include <vector>
#include <set>
#include <queue>
#include <map>

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @brief Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies
 *  of the substring together.
 * 
 * @param s 
 * @return true 
 * @return false 
 */
    bool repeatedSubstringPattern(string s) {
        size_t len = s.length();
        //basic case
        if (len < 2)
            return false;
        bool good = true;
        for (size_t m = 2; m < len; ++m){
            good = true;
            //if string length is divisible by m..
            size_t r = len % m;
            if (r == 0){
                //how many segments we should compare
                size_t n = len / m;
                for (size_t k = 0; k < n - 1; ++k){
                    if (!good)
                        break;
                    for (size_t i = 0; i < m; ++i){
                        size_t pos = i + k*m;
                        if (s[pos] != s[(pos + m)]){
                            good = false;
                            break;
                        }
                    }
                }
                if (good)
                    return true;
                good = true;
            } 
        }
        for (size_t i = 0; i < len - 1; ++i){
            if (s[i] != s[i + 1]){
                good = false;
                break;
            }
        }
        return good;
    }

int main(){
    std::string s = "abab";
    std::cout << "the string is : " << boolalpha << repeatedSubstringPattern(s) << "\n";


    std::cout << " complete\n";
}