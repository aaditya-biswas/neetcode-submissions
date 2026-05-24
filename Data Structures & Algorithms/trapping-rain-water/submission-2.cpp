class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int area = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // Left side is the bottleneck
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update max left wall
                } else {
                    area += left_max - height[left]; // Water trapped above current block
                }
                left++;
            } else {
                // Right side is the bottleneck
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update max right wall
                } else {
                    area += right_max - height[right]; // Water trapped above current block
                }
                right--;
            }
        }
        return area;
    }
};