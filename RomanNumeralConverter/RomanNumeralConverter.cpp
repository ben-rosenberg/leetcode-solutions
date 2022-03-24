#include <iostream>
#include <vector>
#include <string>


/**
 * @brief Roman numeral conversion. 
 */
class Solution
{
public:
    /**
     * @brief Convert a valid Roman Numeral to an integer.
     * 
     * @param s A valid Roman Numeral from 0 <= s <= 3999
     * @return int The base-10 form
     */
    int romanToInt(std::string s)
    {
        std::vector<int> intEquivVector;
        int integerEquivalent;
        int total = 0;
        
        for (int i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
                case 'I': integerEquivalent = 1;
                    break;
                case 'V': integerEquivalent = 5;
                    break;
                case 'X': integerEquivalent = 10;
                    break;
                case 'L': integerEquivalent = 50;
                    break;
                case 'C': integerEquivalent = 100;
                    break;
                case 'D': integerEquivalent = 500;
                    break;
                case 'M': integerEquivalent = 1000;
                    break;
                default: integerEquivalent = -1;
            }
            
            intEquivVector.push_back(integerEquivalent);
        }
        
        for (int i = 0; i < intEquivVector.size(); ++i)
        {
            if (intEquivVector[i] < intEquivVector[i + 1])
            {
                total += intEquivVector[i + 1] - intEquivVector[i];
                i++;
                continue;
            }
            
            total += intEquivVector[i];
        }

        return total;
    }
};

int main()
{
    Solution solution;
    std::string roman1 = "III";
    int expected1 = 3;
    std::string roman2 = "LVIII";
    int expected2 = 58;
    std::string roman3 = "MCMXCIV";
    int expected3 = 1994;

    std::cout << (solution.romanToInt(roman1) == expected1) << "\n";
    std::cout << (solution.romanToInt(roman2) == expected2) << "\n";
    std::cout << (solution.romanToInt(roman3) == expected3) << "\n";
}