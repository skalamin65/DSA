class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1; 
        long long result = 0;
        int prefix = 0; 

        for (int x : arr) {
            prefix = (prefix + x) & 1;
            if (prefix) {
                result += even;
                odd++;
            } else {
                result += odd;
                even++;
            }
            result %= MOD;
        }

        return (int)result;
    }
};