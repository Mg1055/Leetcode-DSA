class Solution {
public:

    bool isPossible(vector<int>& quantities, int maxQ, int stores){
        for(auto x : quantities){
            stores -= x/maxQ;
            if(x % maxQ != 0)   stores--;
            if(stores < 0)  return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi = INT_MIN;
        for(auto x : quantities)
            maxi = max(maxi, x);

        int l = 1, r = maxi;
        while(l <= r){
            int mid = (l+r)/2;
            if(isPossible(quantities, mid, n))
                r = mid-1;
            else 
                l = mid+1;    
        }

        return l;
    }
};