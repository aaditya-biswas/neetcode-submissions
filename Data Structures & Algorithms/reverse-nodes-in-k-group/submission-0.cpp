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
private:
    ListNode * reverse(ListNode * head, int k, ListNode * previous  ) {
        ListNode * cur = head;
        int size = 0;
        while (cur && size < k) {
            size++;
            cur = cur->next;
        
        }
        
        if (size != k ) {
            if (previous) previous->next = head;
             return head;
        }

        ListNode * prev = nullptr;
        cur = head;
        ListNode * next;
        while (size-- ) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (previous) previous->next = prev;
        reverse(next, k , head);
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k ,nullptr);
    }
};
