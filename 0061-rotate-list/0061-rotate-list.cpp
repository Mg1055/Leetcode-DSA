/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void rotatevec(vector<int>& v, int k){
        reverse(v.begin(),v.begin()+(v.size()-k));
        reverse(v.begin()+(v.size()-k),v.end());
        reverse(v.begin(),v.end());
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        vector<int>nums;
        ListNode* curr = head;
        while(curr != NULL){
            nums.push_back(curr->val);
            curr = curr->next;
        }
        if(k >= nums.size())
            k = k%nums.size();
        rotatevec(nums,k);
        curr = head;
        int i = 0;
        while(curr != NULL){
            curr->val = nums[i];
            i++;
            curr = curr->next;
        }
        return head;
    }
};