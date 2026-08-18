class Solution {
public:
    vector<int> prevSmall(vector<int>& nums){
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i< nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmall(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    vector<int> prevBig(vector<int>& nums){
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i< nums.size(); i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> nextBig(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    
    long long sumofmax(vector<int>& nums){
        long long maxsum = 0;
        //const long long mod = 1e9 + 7;
        vector<int> prev = prevBig(nums);
        vector<int> next = nextBig(nums);

        for(int i = 0; i<nums.size(); i++){
            long long p = i - prev[i];
            long long n = next[i] - i;
            maxsum = maxsum + (nums[i] * p * n * 1LL);
        }
        return maxsum;
    }

    long long sumofmin(vector<int>& nums){
        long long minsum = 0;
        //const long long mod = 1e9 + 7;
        vector<int> prev = prevSmall(nums);
        vector<int> next = nextSmall(nums);

        for(int i = 0; i<nums.size(); i++){
            long long p = i - prev[i];
            long long n = next[i] - i;
            minsum = minsum + (nums[i] * p * n * 1LL);
        }
        return minsum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumofmax(nums) - sumofmin(nums);
    }
};