#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int, int> map;

        for (int i : nums1)
            map[i] += 1;

        for (int i : nums2) {
            if (map[i] > 0) {
                v.push_back(i);
                map[i] -= 1;
            }
        }

        return v;
    }
};