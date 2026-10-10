class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, h = 0;

        for(char i : s){
            if(i == '('){
                l++; h++;
            }
            else if(i == ')'){
                l--; h--;
            }
            else{
                l--; h++;
            }
            if(h < 0) return false;
            l = max(0, l);
        }

        return l == 0;
    }
};

/*
)( 

*/