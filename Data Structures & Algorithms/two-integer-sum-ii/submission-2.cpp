class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0 ;
        int r = numbers.size() - 1;
        int n = numbers.size();
        unordered_map<int, int > mp;

        sort(numbers.begin() , numbers.end());
        while (l < r) {
            if (numbers[l] + numbers[r] == target )  {
                return { l +1 ,r + 1  };
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
