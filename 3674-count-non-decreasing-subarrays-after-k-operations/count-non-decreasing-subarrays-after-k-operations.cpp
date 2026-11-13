class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, long long>> dq; 
        long long total = 0;  
        long long sum = 0;    
        long long ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            long long len = 1;
            while (!dq.empty() && dq.front().first <= nums[l]) {
                len += dq.front().second;
                total -= dq.front().first * dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], len});
            total += (long long)nums[l] * len;
            sum += nums[l];

            while (total - sum > k) {
                total -= dq.back().first;
                dq.back().second--;
                if (dq.back().second == 0) dq.pop_back();
                sum -= nums[r];
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};