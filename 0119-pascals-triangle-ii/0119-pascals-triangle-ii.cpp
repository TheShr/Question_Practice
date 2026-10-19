class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long k = 1;
        ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            k = k * (rowIndex + 1 - i);
            k /= i;
            ans.push_back(k);
        }

        return ans; 
    }
};