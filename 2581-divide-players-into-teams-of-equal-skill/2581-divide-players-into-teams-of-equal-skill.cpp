class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<long long, int> um;
        int n = skill.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += skill[i];
            um[skill[i]]++;
        }
         
        int k = (2*sum)/n;
        long long ans = 0;
        int check = 0; 

        for(auto p : um){
            if(um.find(k - p.first) == um.end() || um[k - p.first] != p.second)
                return -1;
            else
                ans += p.second * p.first * (k - p.first);
        }

        return ans/2;
    }
};