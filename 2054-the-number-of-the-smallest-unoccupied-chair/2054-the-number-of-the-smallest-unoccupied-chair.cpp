class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > used_chairs; 
        priority_queue<int, vector<int>, greater<int>> available_chairs;

        for(int i = 0; i < times.size(); i++)   available_chairs.push(i);

        for(int i = 0; i < n; i++)
            times[i].push_back(i);
        sort(times.begin(),times.end());

        for(int i = 0; i < n; i++){
            int arrival_time = times[i][0];  
            int leave_time = times[i][1];
            int ind = times[i][2];
            while(!used_chairs.empty() && used_chairs.top().first <= arrival_time){
                available_chairs.push(used_chairs.top().second);
                used_chairs.pop();
            }  
            int x = available_chairs.top();
            available_chairs.pop();
            used_chairs.push({leave_time, x});

            if(ind == targetFriend) 
                return x; 
        }
        return -1;
    }
};