#include <iostream>
#include <vector>


class Solution
{
public:
    int findCenter(std::vector<std::vector<int>>& edges)
    {
        int possible1 = edges[0][0];
        int possible2 = edges[0][1];

        for (std::vector<int> edge : edges) {
            if (possible1 != edge[0] && possible1 != edge[1]) {
                return possible2;
            }

            if (possible2 != edge[0] && possible2 != edge[1]) {
                return possible1;
            }
        }

        return -1;
    }
};


int main()
{
    Solution s;

    using mtx = std::vector<std::vector<int>>;
    mtx mtx1{ {1, 2}, {2, 3}, {4, 2} };

    std::cout << s.findCenter(mtx1) << '\n';

    mtx mtx2{ {1, 2}, {5, 1}, {1, 3}, {1, 4} };
    std::cout << s.findCenter(mtx2) << '\n';
}