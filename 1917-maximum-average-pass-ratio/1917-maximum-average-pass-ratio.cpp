struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        double ad = (a.first+1)/(double)(a.second+1) - (a.first)/(double)a.second;
        double bd = (b.first+1)/(double)(b.second+1) - (b.first)/(double)b.second;
        return ad < bd;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double acc = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(vector<int> i: classes)
            pq.push({i[0], i[1]});

        while(extraStudents--){
            pair<int,int> curr = pq.top(); 
            pq.pop();
            curr.first++; 
            curr.second++;
            pq.push(curr);
        }

        while(!pq.empty()){
            pair<int,int> curr = pq.top(); 
            pq.pop();
            acc += curr.first / (double) curr.second;
        }

        return acc / (double) classes.size();
    }
};