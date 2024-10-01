class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp; 
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //
        while (left <= mid)
            temp.push_back(arr[left++]);

        //  if elements on the right half are still left //
        while (right <= high)
            temp.push_back(arr[right++]);

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void mergeSort(vector<int>&nums, int low, int high){
        if(low >= high)    return;
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0 , nums.size() - 1);
        return nums;
    }
};