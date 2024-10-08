class Solution {
public:
    int minSwaps(string s) {
        int st_top = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '[')
                st_top++;
            else
                st_top = (st_top > 0) ? st_top - 1 : st_top;
        }
        
        return (st_top + 1)/2;
    }
};