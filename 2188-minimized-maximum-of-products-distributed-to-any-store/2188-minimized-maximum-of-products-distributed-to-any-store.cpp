class Solution {
public:

    bool isPossible(vector<int>&arr, int maxQ, int stores){
        for(auto x : arr){
            stores -= x/maxQ;
            if(x % maxQ != 0)   stores--;
            if(stores < 0)  return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& arr) {
        int maxi = INT_MIN;
        for(auto x : arr)
            maxi = max(maxi, x);

        int l = 1, r = maxi;
        while(l <= r){
            int mid = (l+r)/2;
            if(isPossible(arr, mid, n))
                r = mid-1;
            else 
                l = mid+1;    
        }

        return l;
    }
};