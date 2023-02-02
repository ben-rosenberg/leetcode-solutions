#include <iostream>
#include <vector>
#include <unordered_map>

// Faster than 97.45% of solutions
// Less memory than 72.35% of solutions
class Solution
{
public:
    /**
     * @brief Finds the most frequent even element in an array of numbers
     * 
     * If two even elements tie for the greatest frequency, return the smaller
     * element.
     * 
     * @param nums A vector of integers
     * @return int The most frequent even number in nums
     */
    int mostFrequentEven(std::vector<int> &nums)
    {
        std::unordered_map<int, int> frequency_counter;
        int most_frequent_so_far = -1;
        int most_frequent_count = 0;

        for (const auto num : nums) {
            if (num & 1)
                continue;

            frequency_counter[num]++;

            if (frequency_counter[num] > most_frequent_count
                || (frequency_counter[num] == most_frequent_count
                    && num < most_frequent_so_far))
            {
                most_frequent_so_far = num;
                most_frequent_count = frequency_counter[num];
            }
        }

        return most_frequent_so_far;
    }
};

int main()
{
    Solution s;

    std::vector<int> nums1 = {0, 1, 2, 2, 4, 4, 1};

    std::cout << s.mostFrequentEven(nums1) << '\n';
}