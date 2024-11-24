class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

		for (auto& r : matrix) {
			string s(r.size(), 'T');
			for (int i = 1; i < r.size(); i++) {
				if (r[i] != r[0]) s[i] = 'F';
			}
			mp[s]++;
		}

		int ans = 0;
		for (auto& p : mp)
			ans = max(ans, p.second);
		
		return ans;
    }
};