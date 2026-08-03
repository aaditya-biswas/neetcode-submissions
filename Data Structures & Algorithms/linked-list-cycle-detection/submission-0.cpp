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
    bool hasCycle(ListNode* head) {
        // Floyd hare and tortoise algorithm 
        // Initialize the two pointers 
        if (!head || !head->next) return false;
        ListNode * fast = head;
        ListNode * slow = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
            if (!fast) return false;
        } while (fast != slow);
        return true;
    }
};
