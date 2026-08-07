class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // maxProduct 

        // To solve this we can take two dps 
        // One will calculate the maximum product  subarray 
        // Second one will calculate the minimum product subarray
        // For each index i we will do 
        // max_product[i] represents the maximum product subarray ending at i
        // max_product[i] = max({arr[i]  * max_product[i-1] , arr[i] * min_product[i-1] ,arr[i]} )
        // min_product[i] = min({arr[i] * max_product[i-1], arr[i] * min_product[i-1] , arr[i]});
        // Then output 
        int n = nums.size();
        vector<int> max_product(n ,INT_MIN);
        vector<int> min_product(n , INT_MIN);
        min_product[0] = nums[0];
        max_product[0] = nums[0];
        for (int i = 1; i < nums.size() ; ++i) {
            if (1ll * max_product[i-1] * nums[i] > INT_MAX || 1ll * min_product[i-1] * nums[i] > INT_MAX || 1ll * min_product[i - 1] * nums[i] < INT_MIN) continue; // As it is guaranteed ans will fit into 32 bit integer
            max_product[i] = max({nums[i] , max_product[i-1] * nums[i],  min_product[i-1]  * nums[i]});
            min_product[i] = min({nums[i], max_product[i-1] * nums[i], nums[i] * min_product[i-1] });
        }
        return *max_element(max_product.begin(), max_product.end());
    }
};
