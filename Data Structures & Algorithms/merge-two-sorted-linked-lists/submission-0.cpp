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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2 ) return (list1 ? list1 : list2);
        if (list2->val < list1->val) return mergeTwoLists(list2, list1);
        ListNode * temp_2, *temp_1;
        // Now we are guaranteed list1 <= list2 head
        ListNode * cur = list1;
        while (list2 != nullptr) {
            while (cur->next && cur->next->val <= list2->val ) {
                cur = cur->next;
            }
            // Now insert

            temp_2 = list2->next;
            temp_1 = cur->next;
            cur->next = list2;
            list2->next = temp_1;
            list2 = temp_2;
        }
        return list1;
    }
};
