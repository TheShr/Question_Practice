class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxim = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(') depth++;
            else if(s[i] == ')') depth--;
            maxim = max(depth, maxim);
        }
        if(depth == 0) return maxim;
        else return maxim-depth;
    }
};