class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size());
        
        vector<pair<int ,int>> qp;
        for (int i = 0; i < queries.size(); i++)
            qp.push_back({queries[i], i});
        
        sort(qp.begin(), qp.end());
        sort(items.begin(), items.end());
        
        int k = 0, beauty = 0;
        for (int i = 0; i < qp.size(); i++) {
            int priceAllowed = qp[i].first;
            int queryIndex = qp[i].second;
            
            while (k < items.size() && items[k][0] <= priceAllowed) {
                beauty = max(beauty, items[k][1]);
                k++;
            }
            
            ans[queryIndex] = beauty;
        }
        
        return ans;
    }
};