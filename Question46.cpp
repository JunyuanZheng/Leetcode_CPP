#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void helper(vector<vector<int>> & result, vector<int> & tmp, vector<int> & nums, int idx) {
        if (idx >= (int)nums.size()) {
            result.push_back(tmp);
            return;
        }
        for (int n : nums) {
            if (find(tmp.begin(), tmp.end(), n) == tmp.end()) {
                tmp.push_back(n);
                helper(result, tmp, nums, idx + 1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        helper(result, tmp, nums, 0);
        return result;
    }
};