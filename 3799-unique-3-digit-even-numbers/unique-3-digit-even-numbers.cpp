class Solution {
public:
    // Sk Alamin Hossain
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;
        
        int result = 0;
        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {
                    int need[10] = {0};
                    need[a]++;
                    need[b]++;
                    need[c]++;
                    bool ok = true;
                    for (int d = 0; d < 10; d++) {
                        if (need[d] > cnt[d]) { ok = false; break; }
                    }
                    if (ok) result++;
                }
            }
        }
        return result;
    }
};