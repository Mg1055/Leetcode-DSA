class Solution {
public:

    bool isPossible(vector<int>& weights, int maxDays, int cap){
        int days = 1, n = weights.size();
        int curr_weight = 0;
        for(int i = 0; i < n; i++){
            if(curr_weight + weights[i] > cap){
                days++;
                curr_weight = weights[i];
            }
            else{
                curr_weight += weights[i];
            }
        }

        return days <= maxDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int maxi = INT_MIN, sum = 0;
        for(auto x : weights){
            maxi = max(maxi, x);
            sum += x;
        }

        int l = maxi, r = sum;
        while(l <= r){
            int mid = (r+l)/2;
            if(isPossible(weights, days, mid))
                r = mid-1;
            else
                l = mid+1;
        }
    
        return l;
    }
};