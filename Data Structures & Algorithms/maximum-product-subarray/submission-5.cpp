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
        int max_product;
        int min_product;
        int best_score = nums[0];
        min_product = nums[0];
        max_product = nums[0];
        for (int i = 1; i < nums.size() ; ++i) {
            int temp1 = max_product;
            int temp2 = min_product;
            max_product = max({nums[i] , temp1 * nums[i],  temp2  * nums[i]});
            min_product = min({nums[i], temp1 * nums[i], nums[i] * temp2 });
            best_score = max(best_score, max_product);
        }
        return best_score;
    }
};
