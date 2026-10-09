class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;   
        int open = 0;  
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;          
                } else {
                    ans++;           
                    i += 1;
                }
                if (open > 0) {
                    open--;
                } else {
                    ans++;           
                }
            }
        }

        ans += open * 2;
        return ans;
    }
};