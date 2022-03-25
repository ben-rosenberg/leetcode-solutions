#include <iostream>

/**
 * From leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
 */
class Solution {
public:
    /**
     * @brief Given a positive integer, return how many steps it takes to reduce
     * it to zero by subtracting 1 if odd, and dividing by 2 if even.
     * 
     * Stats for this submission from leetcode.com:
     * 
     * Runtime: 7 ms, faster than 7.25% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
     * Memory Usage: 5.8 MB, less than 94.82% of C++ online submissions for Number of Steps to Reduce a Number to Zero.
     * 
     * @param num A positive integer
     * @return int Number of steps to reduce to 0
     */
    int numberOfSteps(int num)
    {
        int counter = 0;

        for ( ; num > 0; ++counter)
        {
            if (num & 1)
            {
                num -= 1;
                continue;
            }
            num >>= 1;
        }

        return counter;
    }
};

int main()
{
    Solution s;

    int a = 14;
    int aExpected = 6;
    int b = 8;
    int bExpected = 4;
    int c = 123;
    int cExpected = 12;

    std::cout << (s.numberOfSteps(a) == aExpected) << '\n';
    std::cout << (s.numberOfSteps(b) == bExpected) << '\n';
    std::cout << (s.numberOfSteps(c) == cExpected) << '\n';
}