
class Solution {
public:
     int shortestSubarray(vector<int> arr, int k) {
        deque<pair<long long, int>> dq;
        long long sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

            if(sum >= k)
                ans = min(ans, i+1);
            
            while(!dq.empty() and sum - dq.front().first >= k){
                ans = min(ans,i - dq.front().second);
                dq.pop_front();
            }

            while(!dq.empty() and dq.back().first >= sum)
                dq.pop_back();
            dq.push_back({sum,i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};