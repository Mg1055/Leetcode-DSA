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
    struct mycmp{
        bool operator() (struct ListNode* a, struct ListNode* b){
            return a->val > b->val;    
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycmp>minh;

        int k = lists.size();
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL)
                minh.push(lists[i]);
        }

        ListNode *head = NULL, *last = NULL;
        while(minh.empty() == false){
            ListNode *curr = minh.top();
            minh.pop();
            if(curr->next != NULL)
                minh.push(curr->next);
            
            if(head == NULL){
                head = curr;
                last = curr;
            }
            else{
                last->next = curr;
                last = curr;
            }
        }
        return head;
    }
};