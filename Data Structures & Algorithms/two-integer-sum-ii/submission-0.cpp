class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ;
        int r = numbers.size() - 1;
        int n = numbers.size();
        unordered_map<int, int > mp;
        for (int i = 0 ; i < n ; i++) {
            if (mp.find(numbers[i]) == mp.end() ) {
                mp[numbers[i]] = i + 1;
            }
        }
        sort(numbers.begin() , numbers.end());
        while (l < r) {
            if (numbers[l] + numbers[r] == target )  {
                return {min(mp[numbers[l]],mp[numbers[r]]) ,max(mp[numbers[l]],mp[numbers[r]])  };
            }
            else if (numbers[l] + numbers[r] < target) {
                l++;
            }
            else {
                r--;
            }
        }
    return {-1,-1};
    }
};
