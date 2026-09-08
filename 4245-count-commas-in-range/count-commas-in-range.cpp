class Solution {
public:
    // Sk Alamin hossain
    int countCommas(int n) {
        int total=0;
        int d=1;
        while (pow(10,(d-1))<=n){
            int low=pow(10,(d-1));
            int high=min(n,(int) pow(10,d)-1);
            int count_numbers=high-low+1;
            int commas_per_number=(d-1)/ 3;
            total+=count_numbers*commas_per_number;
            d++;
        }
        return (int)total;
    }
};