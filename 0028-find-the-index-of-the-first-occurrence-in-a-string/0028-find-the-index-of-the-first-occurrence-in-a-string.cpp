class Solution {
public:

    void findLPS(string pat, vector<int>&lps){
        int i = 1, len = 0; // len is lps of previous index
        lps[0] = 0;
        int n = pat.size();
        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
    }

    int strStr(string text, string pat) {
        int n = text.size(), m = pat.size();
        // Rabin karp
        // int d = 256;
        // int q = 101; // prime for hashing
        // int h = 0; // base for updating
        // for(int i = 0; i < m-1; i++)
        //     h = (h * d) % q;
        
        // int p = 0, t = 0;  // hash of pattern (p) and text (t)
        // for(int i = 0; i < m; i++){
        //     p = (d * p + pat[i]) % q;
        //     t = (d * t + text[i]) % q;
        // }

        // for(int i = 0; i < n-m+1; i++){
        //     if(p == t){
        //         int j;
        //         for(j = 0; j < m; j++){
        //             if (text[i + j] != pat[j])
        //                 break;
        //         }
        //         if(j == m)
        //             return i; // pattern found
        //     }
    
        //     if(i < n - m){
        //         t = (d * (t - text[i] * h) + text[i + m]) % q;
        //         if(t < 0)
        //             t += q;
        //     }
        // }
        // return -1;

        // KMP
        vector<int>lps(m);
        findLPS(pat, lps);
        int i = 0, j = 0;
        while(i < n){
            if(text[i] == pat[j])
                i++, j++;
            if(j == m)  
                return i-j;
            else if (i < n && pat[j] != text[i]) { 
                if (j == 0) 
                    i++;
                else
                    j = lps[j - 1];  
            }
        }

        return -1;
    }
};