class Solution {
public:
    // Sk Alamin Hossain
    int maxDepth(string s) {
        int depth=0 , max_depth=0;
        for(char c: s){
            if(c == '('){
                depth++;
                max_depth=max(max_depth,depth);
            }
            else if(c==')'){
                depth--;
            }
        }
        return max_depth;
    }
};