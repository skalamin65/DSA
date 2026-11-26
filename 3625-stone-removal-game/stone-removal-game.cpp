class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;         
        bool aliceTurn = true;

        while (k > 0 && n >= k) {
            n -= k;
            k--;
            aliceTurn = !aliceTurn;
        }

    
        return !aliceTurn;
    }
};