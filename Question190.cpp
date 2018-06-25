class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        unsigned int m = 0;
        for (int i = 0; i < 32; i += 1) {
            m <<= 1;
            m |= n & 1;
            n >>= 1;
        }
        return m;
    }
};