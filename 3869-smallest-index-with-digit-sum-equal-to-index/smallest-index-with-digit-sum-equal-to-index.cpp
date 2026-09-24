class Solution {
public:
    // Sk Alamin Hossain
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int x=nums[i];

            int sum=0;
            while(x>0){
                int digit=x%10;
                sum+=digit;
                x/=10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};