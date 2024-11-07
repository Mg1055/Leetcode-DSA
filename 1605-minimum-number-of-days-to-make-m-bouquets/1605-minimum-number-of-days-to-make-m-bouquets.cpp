class Solution {
public:

    bool isPossible(vector<int>&bloomDay, int m, int k, int currDay){
        int n = bloomDay.size();
        int cnt = 0, noOfBqs = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= currDay){
                cnt++;
            }
            else{
                noOfBqs += cnt/k;
                cnt = 0;
            }
        }
        noOfBqs += cnt/k;

        return noOfBqs >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val > n) return -1;

        int l = INT_MAX, r = INT_MIN;
        for(auto x : bloomDay){
            l = min(l, x);
            r = max(r, x);
        }

        while(l <= r){
            int mid = (l+r)/2;
            if(isPossible(bloomDay, m, k, mid))
                r = mid-1;
            else
                l = mid+1;
        }

        return l;
    }
};