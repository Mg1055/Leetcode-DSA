class Solution {
public:
    void printminheap(priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > >minh){
        while(!minh.empty()){
            cout << minh.top()[0] << " " << minh.top()[1] << " " << minh.top()[2] << endl;
            minh.pop();
        }
        cout << endl;
    }

    void printmaxheap(priority_queue< vector<int> >maxh){
        while(!maxh.empty()){
            cout << maxh.top()[0] << " " << maxh.top()[1] << " " << maxh.top()[2] << endl;
            maxh.pop();
        }
        cout << endl;
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue< vector<int> >maxh;
        priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > >minh;

        for(int i = 0; i < k; i++){
            maxh.push({nums[i][0], 0, i});
            minh.push({nums[i][0], 0, i});

        }

        // while(!minh.empty()){
        //     cout << minh.top()[0] << " " << minh.top()[1] << " " << minh.top()[2] << endl;
        //     minh.pop();
        // }
        // cout << endl;
        // while(!maxh.empty()){
        //     cout << maxh.top()[0] << " " << maxh.top()[1] << " " << maxh.top()[2] << endl;
        //     maxh.pop();
        // }
        // return {};

        int l = minh.top()[0];
        int r = maxh.top()[0];
        int ans_interval_size = r - l;

        while(true){
            int num = minh.top()[0];
            int ind = minh.top()[1];
            int list_no = minh.top()[2];
            if(ind == nums[list_no].size()-1)
                break;
            
            // cout << num << " " << ind << " " << list_no << endl;
            // printminheap(minh);
            // printmaxheap(maxh);
            minh.pop();
            ind++;
            minh.push({nums[list_no][ind], ind, list_no});
            maxh.push({nums[list_no][ind], ind, list_no});

            int currL = minh.top()[0], currR = maxh.top()[0];
            int curr_interval_size = currR - currL;
            if(curr_interval_size < ans_interval_size){
                cout << "currL : " << currL << " " << "currR : " << currR << endl;
                l = currL;
                r = currR;
                ans_interval_size = curr_interval_size;
            }
        }

        return {l,r};
    }
};