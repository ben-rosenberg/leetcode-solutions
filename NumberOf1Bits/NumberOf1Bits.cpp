#include <iostream>
#include <vector>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        for (uint32_t rightShiftN = n; rightShiftN > 0; rightShiftN = rightShiftN >> 1) {
            count += rightShiftN & 1;
        }

        return count;
    }
};

int main()
{
    Solution s;

    std::cout << "8: " << s.hammingWeight(8) << '\n';
    std::cout << "14: " << s.hammingWeight(14) << '\n';
}