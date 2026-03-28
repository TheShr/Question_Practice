class Solution {
public:
    long long func(vector<int>& piles, int mid){
        long long totalhrs = 0;
        for(int i = 0; i < piles.size(); i++){
            totalhrs += (piles[i] + mid - 1) / mid;
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        int mx = *max_element(piles.begin(), piles.end());
        int low = 1, high = mx;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(func(piles, mid) <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};