/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        auto current = &dummy;
        while(current -> next && current -> next -> next) {
            auto next_one = current -> next;
            auto next_two = next_one -> next;
            auto next_three = next_two -> next;
            current -> next = next_two;
            next_two -> next = next_one;
            next_one -> next = next_three;
            current = next_one;
        }
        return dummy.next;

    }
};