class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, maxE = 0;
        for(int i = 0; i < n; i++){
            maxE = max(maxE, arr[i]);
            if(maxE == i)
                ans++;
        }
        return ans;
    }
};