class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>maxl(n);
        vector<int>maxr(n);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        
        for(int i = 1; i < n; i++)
            maxl[i] = max(maxl[i-1], height[i-1]);
        for(int i = n-2; i >= 0; i--)
            maxr[i] = max(maxr[i+1], height[i+1]);

        int ans = 0, temp;
        for(int i = 0; i < n; i++){
            temp = min(maxl[i], maxr[i]) - height[i];
            ans += (temp > 0) ? temp : 0;
        }
        return ans;
    }
};