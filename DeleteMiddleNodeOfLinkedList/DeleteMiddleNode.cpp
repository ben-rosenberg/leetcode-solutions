#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief A simple struct for a node in a linked list. 
 */
struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}

    static void print(ListNode* head)
    {
        ListNode* runner = head;

        while (runner != nullptr) {
            std::cout << runner->val << ", ";
            runner = runner->next;
        }

        std::cout << '\n';
    }
};

class Solution
{
public:
    /**
     * @brief Delete the middle node of a linked list and return the head of
     * the modified list.
     * 
     * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
     * 
     * Given a pointer to the head of a linked list, delete the list's middle
     * node and return the head of the new list.
     * 
     * Faster than 46.8% of submissions, less memory than 88.3% of submissions.
     * 
     * @param head A pointer to the head of a linked list.
     * @return ListNode* A pointer to the head of the modified linked list.
     */
    ListNode* deleteMiddle(ListNode* head)
    {
        if (head->next == nullptr) {
            return nullptr;
        }

        int listNodeLength = 0;
        ListNode* runner = head;

        while (runner != nullptr) {
            ++listNodeLength;
            runner = runner->next;
        }

        runner = head;

        for (int i = 0; i < std::floor(listNodeLength / 2) - 1; ++i) {
            runner = runner->next;
        }

        runner->next = runner->next->next;

        return head;
    }
};

int main()
{
    ListNode six(6);
    ListNode five(2, &six);
    ListNode four(1, &five);
    ListNode three(7, &four);
    ListNode two(4, &three);
    ListNode one(3, &two);
    ListNode head(1, &one);
    
    Solution s;
    ListNode* newHead = s.deleteMiddle(&head);

    newHead->print(newHead);
}