class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int>binN;
        int k = n-1;
        while(k > 0){
            binN.push_back(k%2);
            k = k/2;    
        }

        vector<int>binX;
        k = x;
        while(k > 0){
            binX.push_back(k%2);
            k = k/2;    
        }

        int i = 0, j = 0;
        while(i < binX.size() && j < binN.size()){
            if(binX[i] == 0){
                binX[i] = binN[j];
                j++;
            }
            i++;
        }

        while(j < binN.size()){
            binX.push_back(binN[j++]);
        }

        long long p;
        long long ans = 0;
        for(i = 0, p = 1; i < binX.size(); i++, p = p*2)
            ans += (binX[i])*p;
        return ans;
    }
};