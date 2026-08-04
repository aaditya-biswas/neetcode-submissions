/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node * cur = head ;
        Node * head2 = new Node(head->val);
        Node * cur2 = head2;
        Node * temp;
        unordered_map<Node *, Node *> mp;
        while (cur) {
            // Duplicate 
            if (mp.contains(cur)) {
                temp = mp[cur];
            }
            else {
                temp = new Node(cur->val); 
            }
            cur2->next = temp;
            // Now we nned to generate the random pointer 
            mp[cur] = temp;

            if (mp.contains(cur->random)) {
                temp->random = mp[cur->random];
            } else {
                if (cur->random) {
                    mp[cur->random] = new Node(cur->random->val);
                    temp->random = mp[cur->random];
                }
            }
            cur2 = temp;
            cur = cur->next;
        }
        return head2->next;
        
    }
};
