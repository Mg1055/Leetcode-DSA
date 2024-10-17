class Solution {
public:
    int maximumSwap(int num) {
        string str_num = to_string(num);

        int max_i = -1, max_num = -1;
        int left_i = -1, right_i = -1, n = str_num.size();

        for(int i = n-1; i >= 0; i--){
            if(str_num[i] > max_num){
                max_num = str_num[i];
                max_i = i;
                continue;
            }

            if(str_num[i] < max_num){
                left_i = i;
                right_i = max_i;
            }
        }

        if(left_i == -1)    return num;
        swap(str_num[left_i], str_num[right_i]);

        return stoi(str_num);
    }
};