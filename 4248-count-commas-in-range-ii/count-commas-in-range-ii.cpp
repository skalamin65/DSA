class Solution {
public:
    // Sk Alamin Hossain
    long long countCommas(long long n) {
        long long d=1;
        long long total=0;
        while (pow(10,(d-1))<=n){
            long long low=pow(10,(d-1));
            long long high=min(n,(long long)pow(10,d)-1);
            long long count_commas=high-low+1;
            long long commas_per_number=(d-1)/3;
            total+=commas_per_number*count_commas;
            d++;
        }
        return (long long)total;
    }
};