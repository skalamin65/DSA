class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX); 
        
        unordered_map<int,int> prefixIndex; 
        prefixIndex[0] = -1;
        
        long long sum = 0;
        int best = INT_MAX;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (prefixIndex.count(sum - target)) {
                int start = prefixIndex[sum - target]; 
                int len = i - start;
                
                if (start >= 0 && minLen[start] != INT_MAX) {
                    ans = min(ans, minLen[start] + len);
                }
                
                best = min(best, len);
            }
            
            minLen[i] = best; 
            
            prefixIndex[sum] = i;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};