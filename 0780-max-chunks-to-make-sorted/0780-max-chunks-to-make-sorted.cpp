class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>maxE(n);
        maxE[0] = arr[0];
        for(int i = 1; i < n; i++)
            maxE[i] = max(maxE[i-1], arr[i]);

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(maxE[i] == i)
                ans++;
        }
        return ans;
    }
};