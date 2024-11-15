class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size(), left = 0, right = N - 1;
        while (left + 1 < N && arr[left] <= arr[left + 1])
            left++;
        if (left == arr.size() - 1) return 0;
        while (right > left && arr[right - 1] <= arr[right]) 
            right--;
        int ans = min(N - left - 1, right), i = 0, j = right;
        while (i <= left && j < N) {
            if (arr[j] >= arr[i]) {
                ans = min(ans, j - i - 1);
                i++;
            } else
                j++;
        }
        return ans;
    }
};