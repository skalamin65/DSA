class Solution {
public:
    // Sk Alamin Hossain
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        
        // suffix min: sufMin[i] = min(nums[i..n-1])
        vector<int> sufMin(n);
        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        }
        
        // sweep prefix max left to right, checking condition on the fly
        int curMax = nums[0];
        for (int i = 0; i < n; i++) {
            curMax = max(curMax, nums[i]);
            if ((long long)curMax - sufMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};