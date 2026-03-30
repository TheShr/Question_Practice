class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) low = mid + 1;
            else high = mid - 1;

        }
        return high + 1 + k;
    }
};

/*

arr = [1,2,3,4], k = 2

0 0 0 0 

*/