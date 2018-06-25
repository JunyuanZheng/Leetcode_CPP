class Solution {
public:
    int hammingWeight(unsigned int n) {
        int counter = 0;
        while (n != 0) {
            n &= (n - 1);
            counter += 1;
        }
        return counter;
    }
};