#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int result = 0;
        int l = 0, h = (int) height.size() - 1;
        while (l < h) {
            result = max(result, (min(height[l], height[h]) * (h - l)));
            if (height[l] < height[h])
                l++;
            else
                h--;
        }
        return result;
    }
};