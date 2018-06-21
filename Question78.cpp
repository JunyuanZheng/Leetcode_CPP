#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void helper(vector<int> & nums, vector<vector<int>> & result, vector<int> & memo, int idx) {
        result.push_back(memo);
        for (int i = idx; i < (int) nums.size(); i += 1) {
            memo.push_back(nums[i]);
            helper(nums, result, memo, i + 1);
            memo.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> memo;
        helper(nums, result, memo, 0);
        return result;
    }
};