#include <vector>
#include <unordered_map>

class Question1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i += 1) {
            int value = target - nums[i];
            if (hash.find(value) != hash.end()) {
                result.push_back(hash[value] + 1);
                result.push_back(i + 1);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};