class Solution {
public:

    void sieve(int n, vector<int>&nums){
        vector<bool>isPrime(n+1,true);
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i] == true){
                for(int j = i*i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for(int i = 2; i <= n; i++){
            if(isPrime[i])
                nums.push_back(i);
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        cout << "n: " << n << endl;
        vector<int>primes;
        sieve(1000, primes);
        for(int i = n-2; i >= 0; i--){
            if(nums[i] >= nums[i+1]){
                int dif = nums[i] - nums[i+1];
                auto it = upper_bound(primes.begin(), primes.end(), dif);
                int p = *it;
                cout << "i: " << i << " p: " << p << endl;
                if(it == primes.end() || p >= nums[i])
                    return false;
                nums[i] -= p;
            }
        }

        return true;
    }
};