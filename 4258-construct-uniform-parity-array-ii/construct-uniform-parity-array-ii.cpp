class Solution {
public:
    // Sk Alamin Hossain
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        bool hasOdd = false, hasEven = false;
        
        for (int x : nums1) {
            if (x % 2 == 1) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            } else {
                hasEven = true;
                minEven = min(minEven, x);
            }
        }
        
        if (!hasOdd || !hasEven) {
            return true;
        }
        
        return minOdd < minEven;
    }
};