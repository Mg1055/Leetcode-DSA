class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>vec;
        int n = arr.size();

        if(n == 0)
            return arr;
        for(int i = 0; i < n; i++)
            vec.push_back({arr[i], i});
        sort(vec.begin(), vec.end());

        int prevScore = vec[0].first;
        vec[0].first = 1;
        int prevRank = 1;
        for(int i = 1; i < n; i++){
            if(vec[i].first == prevScore)
                vec[i].first = prevRank;
            else{
                prevScore = vec[i].first;
                vec[i].first = ++prevRank;
            }
        }

        for(auto x : vec){
            arr[x.second] = x.first;
        }

        return arr;
    }
};