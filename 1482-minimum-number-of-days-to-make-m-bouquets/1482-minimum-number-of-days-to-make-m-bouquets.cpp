class Solution {
public:
    bool func(int mid, vector<int>& bloomDay, int k, int m){
        int cnt = 0, numOfB = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else{
                numOfB += cnt/k;
                cnt = 0;
            }
        }
        numOfB += cnt/k;
        if(numOfB >= m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
        if((long long)m*k > (long long)n) return -1;
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i<n; i++){
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }
        while(low <= high){
            int mid = (low+high)/2;
            if(func(mid, bloomDay, k, m)) high = mid -1;
            else low = mid + 1;
        }
        return low;

    }
};

/* 
if m*k < n return -1;

1 ------> 10 , m = 5 

-> 
*/