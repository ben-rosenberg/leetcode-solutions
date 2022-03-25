#include <vector>
#include <iterator>
#include <iostream>

/**
 * From leetcode.com/problems/remove-duplicates-from-sorted-array/
 */
class Solution
{
public:

    /**
     * @brief Modify a sorted array so that the first k elements contain no duplicate
     * values, return k.
     * 
     * Data on this submission from Leetcode:
     * 
     * Runtime: 16 ms, faster than 58.59% of C++ online submissions for Remove Duplicates from Sorted Array.
     * Memory Usage: 18.5 MB, less than 37.39% of C++ online submissions for Remove Duplicates from Sorted Array.
     * 
     * @param nums A vector of sorted integers
     * @return int The number of unique values in the vector
     */
    int removeDuplicates(std::vector<int>& nums)
    {
        std::vector<int>::iterator insertPtr = nums.begin();
        int previousVal = *insertPtr;
        int counter = 1;

        for (std::vector<int>::iterator it = insertPtr + 1; it != nums.end(); ++it)
        {
            if ((*it) != previousVal)
            {
                ++counter;
                ++insertPtr;
                *insertPtr = *it;
            }
            else
            {
                continue;
            }
            
            previousVal = *it;
        }
        
        return counter;
    }
};

int main()
{
    Solution s;
    std::vector<int> test = { 1, 1, 2, 3, 3, 3, 3, 4, 8, 9, 10, 10 };

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
        std::cout << *it << ", ";
    std::cout << "\n";

    int result = s.removeDuplicates(test);

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
        std::cout << *it << ", ";
    std::cout << "\n" << result << "\n";
}