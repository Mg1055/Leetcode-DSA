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

    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2sLL(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1){
            curr->next = l1;
        }
        
        if(l2){
            curr->next = l2;
        }
        ListNode *temp = dummy->next;
        delete dummy;
        return temp;
    }

    ListNode* sortList(ListNode* head) {
       if(head == NULL || head->next == NULL)   return head;
       ListNode* mid = findMid(head);
       ListNode* right = mid->next;
       mid->next = NULL;
       ListNode* left = head;

       left = sortList(left);
       right = sortList(right);
       return merge2sLL(left, right);
    }
};