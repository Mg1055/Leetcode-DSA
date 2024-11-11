class Solution {
public:

    void findLPS(string pat, vector<int>&lps){
        int i = 1, j = 0;
        int m = pat.size();
        while(i < m){
            if(pat[i] == pat[j]){
                lps[i] = j+1;
                i++;j++;
            }
            else if(j > 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
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
        while(i < n && j < m){
            if(text[i] == pat[j]){
                i++, j++;
            } 
            else if(j > 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }

        return j == pat.size() ? i-j : -1;
    }
};