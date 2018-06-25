#include <vector>

using namespace std;

/*
A little more explanation to OPs code:

Like in Qstn Maximum sum subarray here (https://leetcode.com/problems/maximum-subarray/description/), for applying a DP soln, we keep a count of the maximum sum subarray that ends at each element of nums[i].

Here, we do the same thing, but we also include the minimum product for the subarray that ends at each of the elements of nums[i]. Why do we need minima at each of the nums[i]?

Ex: [2, 3, -2, 4]
i_max: 2, 6, -2, 4

We don't have i_min here. If the array had a negative no. again, say -3, i.e.,

Ex: [2, 3, -2, 4, -3]

then negative and negative would have become positive and the i_min at -2 would have come in handy. That's why we maintain i_mins. Also, at each i, if the nums[i] is negative, then to calculate the true i_max and true_i_min, we swap the i-1_max and i-1_min for obvious reasons (bigger no multiplied with neg becomes smaller as compared to when a smaller no was multiplied to the negative no.)

This way, we maintain the maximum and minimum products for subarrays ending at each i.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1, imax = result, imin = result; i < nums.size(); i += 1) {
            if (nums[i] < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            result = max(result, imax);
        }
        return result;
    }
};