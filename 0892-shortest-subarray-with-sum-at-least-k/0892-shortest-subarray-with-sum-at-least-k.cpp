
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>> > pq;
        long long sum = 0;
        long long ans = 1e18;
        for(long long i = 0; i < nums.size(); i++){
            sum += (long long)nums[i];
            if(sum >= k)
                ans = min(ans, i+1);
            
            while(pq.size() && sum - pq.top().first >= k){
                auto p = pq.top();
                ans = min(ans, i - p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == 1e18 ? -1 : ans;
    }
};