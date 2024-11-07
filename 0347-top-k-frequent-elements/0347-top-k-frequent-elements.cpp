class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        for(auto x: nums)
            um[x]++;
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto x: um){
            pq.push({x.second,x.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int>ans;
        while(pq.empty() == false){
            auto p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
    }
};