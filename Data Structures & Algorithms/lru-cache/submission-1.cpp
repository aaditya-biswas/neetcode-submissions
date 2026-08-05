class Node {
    public:
        Node * prev;
        Node * next;
        int key;
        int val;
        Node() : val(-1), key(0), prev(nullptr), next(nullptr){};
        Node(int val_) : val(val_), key(0), prev(nullptr), next(nullptr) {};
};


class LinkedList{
    public:
        int size = 0, max_sz = 0;
        unordered_map<int,Node *> mp;
        Node * start;
        Node * end;
        LinkedList(int max_size) {
            max_sz = max_size;
            start = new Node();
            end = new Node();
            start->next = end;
            end->prev = start;
        }
        int get_size() {
            return size;
        }
        int get(int key) {
            if (mp.contains(key)) { 
                // Disconnect
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                // Shift it to the back
                end->prev->next = mp[key];
                mp[key]->prev = end->prev;
                mp[key]->next = end;
                end->prev = mp[key];
                return mp[key]->val;
            }
            return -1;
        }
        void put(int key , int value) {
            if (get(key) != -1) {
                mp[key]->val = value;
                // Disconnect the node 

               
            }
            else {
                size++;
                if (size > max_sz) deleteFrontNode();
                Node * a = new Node(value);
                a->key = key;
                mp[key] = a;
                end->prev->next = a;
                a->next = end;
                a->prev = end->prev;
                end->prev = a;

            }
            return ;

        }   
        void deleteFrontNode() {
            size--;
            Node * temp = start->next;
            mp.erase(temp->key);
            temp->next->prev = start;
            start->next = temp->next;
            delete temp;
        }
};




class LRUCache {
public:
    LinkedList * lru;
    LRUCache(int capacity) {
        lru = new LinkedList(capacity);
    }
    
    int get(int key) {
        return lru->get(key);
        
    }
    
    void put(int key, int value) {
        lru->put(key , value);
    }
};
