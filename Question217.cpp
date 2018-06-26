#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
        for (int i : nums) {
            if (set.find(i) == set.end())
                set.insert(i);
            else
                return true;
        }
        return false;
    }
};