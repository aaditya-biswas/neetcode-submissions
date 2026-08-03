class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Got the midpoint
        // Reverse from the midpoint + 1 to the end of the list
        ListNode * prev = nullptr;
        ListNode * cur = slow->next;
        slow->next = nullptr;
        ListNode * temp , * temp2;
        while (cur ) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;

        }
        ListNode * cur_2 = prev;
        cur = head;

        while (cur_2 ) {
            temp2 = cur_2->next;
            temp = cur->next;
            cur_2->next = cur->next;
            cur->next = cur_2;
            cur = temp;
            cur_2 = temp2;

        }
        return;
    }
};