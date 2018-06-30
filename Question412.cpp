#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i = 1; i <= n; i += 1) {
            if (i % 3 == 0 && i % 5 == 0)
                v.emplace_back("FizzBuzz");
            else if (i % 3 == 0)
                v.emplace_back("Fizz");
            else if (i % 5 == 0)
                v.emplace_back("Buzz");
            else
                v.emplace_back(to_string(i));
        }
        return v;
    }
};