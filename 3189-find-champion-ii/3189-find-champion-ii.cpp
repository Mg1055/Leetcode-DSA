class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegrees(n,0);
        for(int i = 0; i < edges.size(); i++){
            indegrees[edges[i][1]]++;
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(indegrees[i] == 0){
                if(ans != -1)  return -1;
                ans = i;
            }
        }
        return ans;
    }
};