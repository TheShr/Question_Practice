class Solution {
private: stack<char> bkts;
public:
    bool isalid(string s) {
        for(char ch : s){
            if(ch == '(' ||ch == '[' || ch == '{'){
                bkts.push(ch);
            }
            else{
                if(bkts.empty()) return false;
                if(ch == ')' && bkts.top() != '('|| 
                   ch == ']' && bkts.top() !='['||
                   ch == '}' && bkts.top() != '{'){
                    return false;
                }
                bkts.pop();
            }
        }return bkts.empty();
    }
};