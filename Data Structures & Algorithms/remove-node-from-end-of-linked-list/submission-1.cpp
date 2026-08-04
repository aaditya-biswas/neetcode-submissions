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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Length of the list 
        int len = 0;
        ListNode * cur = head;
        while (cur ) {
            len++;
            cur = cur->next;
        }
        ListNode * temp_head = new ListNode(0,head);
        int req = len - n +1 ;
        cur = temp_head;
        int ind = 1;
        while (cur ) {
            if (ind == req) {
                ListNode * temp =  cur->next->next;
                delete cur->next;
                cur->next = temp;
                return temp_head->next;
            } 
            cur = cur->next;
            ind++;
        }

    }
};
