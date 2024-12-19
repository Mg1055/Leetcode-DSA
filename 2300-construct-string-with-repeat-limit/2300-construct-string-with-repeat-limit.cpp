class Solution {
public:
    string repeatLimitedString(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(auto c : s)
            mp[c]++;

        priority_queue<pair<char,int>>pq;
        for(auto i : mp)
            pq.push({i.first, i.second});
        
        string ans = "";
        while(!pq.empty()){
            char largestElement = pq.top().first;
            int LargestElementFreq = pq.top().second;
            pq.pop();

            int toAdd = min(LargestElementFreq, k);
            for(int i = 0; i < toAdd; i++)  ans += largestElement;
            LargestElementFreq -= toAdd;

            char SndLargestElement;
            int SndLargestElementFreq = 0;
            if(LargestElementFreq > 0){ 
                if(pq.empty())
                    return ans;
                SndLargestElement = pq.top().first;
                SndLargestElementFreq = pq.top().second;
                
                pq.pop();
                ans += SndLargestElement;
                SndLargestElementFreq--;
                
                pq.push({largestElement, LargestElementFreq});
                if(SndLargestElementFreq > 0) 
                    pq.push({SndLargestElement, SndLargestElementFreq}); 
            }
        }
        return ans;
    }
};