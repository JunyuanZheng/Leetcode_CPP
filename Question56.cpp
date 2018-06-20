#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool custom (Interval const & i1, Interval const & i2) {
    return i1.start < i2.start;
}

class Solution {
public:
    vector <Interval> merge(vector <Interval> &intervals) {
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), custom);
        for (Interval interval : intervals) {
            if (result.empty()) {
                result.push_back(interval);
            } else {
                Interval i = result[result.size() - 1];
                if (i.end >= interval.start) {
                    result.erase(result.end() - 1);
                    i.end = max(interval.end, i.end);
                    result.push_back(i);
                } else {
                    result.push_back(interval);
                }
            }
        }
        return result;
    }
};