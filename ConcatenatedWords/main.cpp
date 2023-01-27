#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

/**
 * @brief Leetcode Problem #472: Concatenated Words
 * 
 * Faster than 71%.
 * Less memory than 90%.
 * 
 * Probably could use a good refactor, but I am proud of this solution.
 * 
 * "Given an array of strings words (without duplicates), return all the
 * concatenated words in the given list of words.
 * 
 * "A concatenated word is defined as a string that is comprised entirely of at
 * least two shorter words in the given array."
 */
class Solution
{
    bool _processWord(std::string word, int starting_idx = 0)
    {
        std::string curr_str = "";

        for (int i = starting_idx; i < word.length(); i++) {
            curr_str += word[i];

            if (_wordsSet.find(curr_str) != _wordsSet.end()) {
                if (i == word.length() - 1 && curr_str.length() < word.length()) {
                    return true;
                }

                if (_processWord(word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    std::vector<std::string> findAllConcatenatedWordsInDict(std::vector<std::string> &words)
    {
        std::vector<std::string> all_concatenated_words;

        for (const auto &word : words) {
            _wordsSet.insert(word);
        }

        for (const auto &word : words) {
            if (_processWord(word))
                all_concatenated_words.push_back(word);
        }

        return all_concatenated_words;
    }

private:
    std::unordered_set<std::string> _wordsSet;
};

int main()
{
    Solution s;

    std::vector<std::string> words1 = { "cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };
    std::vector<std::string> words2 = { "cat", "dog", "dogcat" };

    std::vector<std::string> all_concatenated_words = s.findAllConcatenatedWordsInDict(words1);

    for (const auto &word : all_concatenated_words) {
        std::cout << word << '\n';
    }
}