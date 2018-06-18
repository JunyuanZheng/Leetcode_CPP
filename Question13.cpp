#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> lut {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;

        for (auto pointer = s.cbegin(); pointer != s.cend(); pointer += 1)
            result += lut[*pointer];

        if (s.find("IV") != string::npos)
            result -= 2;
        if (s.find("IX") != string::npos)
            result -= 2;
        if (s.find("XL") != string::npos)
            result -= 20;
        if (s.find("XC") != string::npos)
            result -= 20;
        if (s.find("CD") != string::npos)
            result -= 200;
        if (s.find("CM") != string::npos)
            result -= 200;

        return result;
    }
};