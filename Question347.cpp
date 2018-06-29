#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums)
            map[n] += 1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto value : map) {
            pq.push({ value.second, value.first });
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};