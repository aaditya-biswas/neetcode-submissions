class Solution {
public:
    void constructIternary(string airport, vector<string>& temp, unordered_map<string, multiset<string>>& mp) {
        // 1. Consume outgoing flights continuously until none are left
        while (!mp[airport].empty()) {
            auto it = mp[airport].begin();
            string neighbor = *it;
            mp[airport].erase(it); // Erase the ticket permanently (no re-insertion!)
            
            constructIternary(neighbor, temp, mp);
        }
        
        // 2. POST-ORDER: Push airport to temp AFTER all sub-paths are fully traversed
        temp.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (int i = 0; i < tickets.size(); i++) {
            mp[tickets[i][0]].insert(tickets[i][1]); // multiset keeps lexicographical order
        }

        vector<string> temp;
        constructIternary("JFK", temp, mp);

        // 3. Post-order produces path in reverse, so reverse it back
        reverse(temp.begin(), temp.end());
        return temp;
    }
};