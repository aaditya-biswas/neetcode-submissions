#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: Sorted String -> List of Original Strings
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s; 
            sort(key.begin(), key.end()); // Sort to create the unique key
            groups[key].push_back(s);     // Push the original string into the group
        }

        // Move the grouped vectors into the final result
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(move(pair.second));
        }

        return result;
    }
};