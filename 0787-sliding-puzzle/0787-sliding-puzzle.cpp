class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string required = "123450";
        
        string begin = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                begin += to_string(board[i][j]);
            }
        }

        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> visited;
        visited.insert(begin);
        queue<pair<string, int>> q;
        q.push({begin, 0});
        while(!q.empty()) {
            auto p = q.front(); 
            q.pop();
            string curr = p.first;
            int dist = p.second;
            int idx = curr.find("0");

            if(curr == required)
                return dist;

            for(auto k : moves[idx]) {
                string next = curr;
                swap(next[idx], next[k]);
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
        return -1;
    }
};