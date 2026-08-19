class Solution {
public:
    vector<int> prevSmall(vector<int>& heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i< heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]) st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmall(vector<int>& heights){
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    int largestRectangleArea(vector<int>& heights) {
        long long ans = INT_MIN;
        //const long long mod = 1e9 + 7;
        vector<int> prev = prevSmall(heights);
        vector<int> next = nextSmall(heights);

        for(int i = 0; i<heights.size(); i++){
            long long idx = next[i] - prev[i] - 1;
            ans = max(heights[i]*idx, ans);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> heights(c, 0);

        int ans = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        
        return ans;
    }
};