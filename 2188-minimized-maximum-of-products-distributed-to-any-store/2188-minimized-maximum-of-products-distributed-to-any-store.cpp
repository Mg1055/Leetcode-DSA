class Solution {
public:

    bool isPossible(vector<int>&arr, int maxQ, int stores){
        for(auto x : arr){
            stores -= (x + maxQ -1)/maxQ;
            if(stores < 0) 
                return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int l = 1, r = arr[arr.size() - 1];
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