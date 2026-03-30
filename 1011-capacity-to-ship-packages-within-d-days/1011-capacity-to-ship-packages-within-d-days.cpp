class Solution {
public:
    bool func(int mid , vector<int>& weights , int days){
        int sum = 0, cnt = 1;
        for(int i = 0; i<weights.size(); i++){
            if(sum + weights[i] > mid){
                cnt++;
                sum = weights[i];
            }
            else sum += weights[i];
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i<weights.size(); i++){
            high += weights[i];
        }
        //high = high/days;
        while(low <= high){
            int mid = (low+high)/2;
            if(func(mid, weights, days)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

/*
weights = [1,2,3,4,5,6,7,8,9,10]
maxCap = 15
divde by days and sum:
1 + 1 + 1 + 1 + 1 + 2 + 2 + 2 + 2 + 2 = 15

weights = [3,2,2,4,1,4], days = 3
maxCap = 
1 + 1 + 1 + 2 + 1 + 2


weights = [1,2,3,1,1], days = 4

1 + 1 + 1 + 1 + 1 = 5 <- upper limit, lower limit -> max of vector

1 2 3 4 5 

is the sum of these giving upper limit ?
*/