class Solution {
private: 
    vector<int> prevSmall(vector<int>& arr){
        int n = arr.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i = 0; i< arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmall(vector<int>& arr){
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        const long long mod = 1e9 + 7;
        vector<int> prev = prevSmall(arr);
        vector<int> next = nextSmall(arr);

        for(int i = 0; i<arr.size(); i++){
            long long p = i - prev[i];
            long long n = next[i] - i;
            ans = (ans + (arr[i] * p * n * 1LL)%mod) % mod;
        }
        return ans;

    }
};

/*
we can reduce the multiple subarrs to individual contribution, 

for that i need to know prev small elemenet and next small element for every element!



*/