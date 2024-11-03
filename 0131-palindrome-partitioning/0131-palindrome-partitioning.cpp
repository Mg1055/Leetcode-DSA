class Solution {
public:

    vector<vector<string>>ans;

    bool isPallindrome(string s, int l, int r){
        while(l <= r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void f(int parition_index, string s, vector<string>&temp){
        if(parition_index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = parition_index; i < s.size(); i++){
            if(isPallindrome(s, parition_index, i)){
                temp.push_back(s.substr(parition_index, i - parition_index + 1));
                f(i+1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>temp;
        f(0, s, temp);
        return ans;
    }
};