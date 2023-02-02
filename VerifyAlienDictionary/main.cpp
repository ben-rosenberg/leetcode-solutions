#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Faster than 59%
// Less memory than 49%
class Solution
{
public:
    /**
     * @brief Determines if an array of words is lexicographically sorted
     * according to a reordered alphabet.
     * 
     * @param order The letters of the English alphabet in a new order
     * @param words A vector of words containing lowercase English letters
     * @return true If the words are sorted according to the new alphabet
     * @return false If the words are not sorted
     */
    bool isAlienSorted(std::string order, std::vector<std::string> &words)
    {
        std::unordered_map<char, int> alpha_map;

        for (auto i = 0; i < order.length(); ++i) {
            alpha_map[order[i]] = i;
        }

        for (auto i = 0; i < words.size() - 1; ++i) {
            int char_idx = 0;

            while (words[i][char_idx] == words[i + 1][char_idx] 
                   && char_idx < words[i].length()
                   && char_idx < words[i + 1].length())
            {
                char_idx++;
            }

            // first char_idx - 1 characters are the same, but current word is
            // longer than next word, making it not sorted
            if (char_idx == words[i + 1].length() && char_idx < words[i].length())
                return false;

            if (alpha_map[words[i][char_idx]] > alpha_map[words[i + 1][char_idx]])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;


}