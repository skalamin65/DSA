class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        long long total = 0;
        for (int x : nums) total += mx - x;
        return (int)total;
    }
};