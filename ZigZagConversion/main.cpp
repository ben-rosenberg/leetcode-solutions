#include <iostream>
#include <string>
#include <vector>

class ZigZagCounter
{

};

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (s.length() <= numRows)
            return s;
        
        std::string zigzag_converted = "";

        for (auto i = 0; i < numRows; ++i) {
            zigzag_converted += s[i];

            auto row = i;
            bool is_ascending = i < numRows - 1;

            for (int idx = i + 1; idx < s.length(); ++idx) {
                row += is_ascending ? 1 : -1;
                
                if (row == numRows - 1) {
                    is_ascending = false;
                } else if (row == 0) {
                    is_ascending = true;
                }

                if (row == i) {
                    zigzag_converted += s[idx];
                }
            }
        }

        return zigzag_converted;
    }
};

int main()
{
    Solution s;

    std::string s1 = "PAYPALISHIRING";
    int num_rows1 = 4;
    std::string const expected1 = "PINALSIGYAHRPI";

    int num_rows2 = 3;
    std::string const expected2 = "PAHNAPLSIIGYIR";

    std::cout << s1 << " (" << num_rows1 << " rows): " << expected1 << '\n';
    std::cout << "Conversion: " << s.convert(s1, num_rows1) << "\n\n";

    std::cout << s1 << " (" << num_rows2 << " rows): " << expected2 << '\n';
    std::cout << "Conversion: " << s.convert(s1, num_rows2) << '\n';
}