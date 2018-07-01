#include <vector>
#include <algorithm>

using namespace std;

class RandomizedSet {
private:
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (find(v.begin(), v.end(), val) != v.end())
            return false;
        v.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto position = find(v.begin(), v.end(), val);
        if (position == v.end())
            return false;
        v.erase(position);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};
