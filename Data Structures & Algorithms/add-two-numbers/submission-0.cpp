class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reversel1 = l1;
        ListNode* reversel2 = l2;
        
        ListNode* cur1 = reversel1;
        ListNode* cur2 = reversel2;
        ListNode* prev = nullptr;
        
        int longer = 1; // Fixed: int instead of bool
        int carry = 0;

        while (cur1 && cur2) {
            int val = cur1->val + cur2->val + carry;
            cur1->val = val % 10;
            cur2->val = val % 10;
            carry = val / 10;
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while (cur2) {
            int val = cur2->val + carry;
            cur2->val = val % 10;
            carry = val / 10;
            prev = cur2;
            longer = 2; // Now correctly sets longer to 2
            cur2 = cur2->next;
        }

        while (cur1) {
            int val = cur1->val + carry;
            cur1->val = val % 10;
            carry = val / 10;
            prev = cur1;
            cur1 = cur1->next;
        }

        while (carry) {
            ListNode* a = new ListNode(carry % 10);
            carry /= 10;
            if (prev) prev->next = a;
            prev = a;
        }

        return (longer == 1) ? reversel1 : reversel2;
    }
};