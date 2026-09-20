class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int value = 26 - (s[i] - 'a');
            total += value * (i + 1);
        }
        return total;
    }
};