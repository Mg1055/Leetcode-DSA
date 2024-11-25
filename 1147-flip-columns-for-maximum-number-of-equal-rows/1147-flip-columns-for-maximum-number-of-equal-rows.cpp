class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

		for (auto &row : matrix) {
            string pattern = "";
            if (row[0] == 0)
                for (int bit : row) pattern += to_string(bit);
            else
                for (int bit : row) pattern += to_string(bit ^ 1);
			mp[pattern]++;
		}

		int ans = 0;
		for (auto &p : mp)
			ans = max(ans, p.second);
		return ans;
    }
};