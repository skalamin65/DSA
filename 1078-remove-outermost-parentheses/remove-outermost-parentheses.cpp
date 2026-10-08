class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) result += c;  // skip the outermost '('
                depth++;
            } else {
                depth--;
                if (depth > 0) result += c;  // skip the outermost ')'
            }
        }

        return result;
    }
};