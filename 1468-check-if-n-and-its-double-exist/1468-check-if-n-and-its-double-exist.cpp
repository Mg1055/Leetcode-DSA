class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            mp[arr[i]] = i;
        for(int i = 0; i < n; i++){
            int doubleNum = arr[i]*2;
            if(mp.find(doubleNum) != mp.end()){
                if(mp[doubleNum] != i)
                    return true;
            }
        }
        return false;
    }
};