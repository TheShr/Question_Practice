class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int prefixMax[n], suffixMax[n];

        for(int i = 1; i<n-1; i++){
            prefixMax[0] = height[0];
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }
        for(int i = n-2; i>=0; i--){
            suffixMax[n-1] = height[n-1];
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        for(int i = 1; i<n-1; i++){
            ans += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return ans;
    }
};