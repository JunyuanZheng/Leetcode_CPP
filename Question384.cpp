#include <vector>

using namespace std;

class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int> nums) {
        v = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result (v);
        for (int i = (int) result.size() - 1; i >= 0; i -= 1) {
            int tmp = rand() % (i + 1);
            swap(result[i], result[tmp]);
        }
        return result;
    }
};