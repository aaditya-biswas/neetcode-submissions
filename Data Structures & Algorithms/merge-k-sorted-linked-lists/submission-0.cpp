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
    ListNode * merge(ListNode * l1 , ListNode * l2 ) {
        ListNode * dummy = new ListNode();
        ListNode * cur = dummy, * cur_l1 = l1, * cur_l2 = l2 ; 
        while (cur_l1 && cur_l2 ) {
            if (cur_l1->val <= cur_l2->val ) { 
                cur->next = cur_l1;
                cur = cur_l1;
                cur_l1 = cur_l1->next;
            }
            else {
                cur->next = cur_l2 ;
                cur = cur_l2;
                cur_l2 = cur_l2->next;
            }
        }
        while (cur_l1) {
            cur->next = cur_l1;
            cur = cur_l1;
            cur_l1 = cur_l1->next;
   
        }
        while (cur_l2) {
            cur->next = cur_l2;
            cur = cur_l2;
            cur_l2 = cur_l2->next;
        }
        return dummy->next;
    }

    ListNode * divide(int l , int r ,vector<ListNode * > & lists  ) {
        if (l  == r ) return lists[l];
        int mid = l + (r - l ) / 2;
        ListNode * left = divide(l ,mid , lists);
        ListNode * right = divide(mid + 1, r ,lists);
        return (merge(left,right));
    }
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        // Merging k sorted lists 
        return divide(0, lists.size() - 1, lists);
    }
};
