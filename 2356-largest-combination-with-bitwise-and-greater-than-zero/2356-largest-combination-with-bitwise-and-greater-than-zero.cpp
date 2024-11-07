class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n = arr.size();
        vector<int>setBits(24,0);
        for(auto x : arr){
            int k = x;
            int i = 0;
            while(k > 0){
                setBits[i++] += k%2;
                k = k/2;
            }
        }

        int ans = 1;
        for(auto x : setBits)
            ans = max(x, ans);
        
        return ans;
    }
};