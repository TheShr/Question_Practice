class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k = start ^ goal;
        int ans = 0;
        while(k != 0){
            k = k&(k-1);
            ans++;
        }
        return ans;
    }
};