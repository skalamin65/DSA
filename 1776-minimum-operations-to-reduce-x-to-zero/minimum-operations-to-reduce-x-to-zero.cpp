class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;
        
        int target = total - x;
        if (target < 0) return -1; // x is too large even removing everything
        if (target == 0) return nums.size(); // remove everything
        
        int n = nums.size();
        int left = 0, sum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }
            
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};