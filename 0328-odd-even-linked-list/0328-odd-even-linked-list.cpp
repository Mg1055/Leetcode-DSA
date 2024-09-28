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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode *oddEnd = head, *evenEnd = head->next;
        while(evenEnd != NULL && evenEnd->next != NULL){
            ListNode* temp1 = oddEnd->next;
            oddEnd->next = evenEnd->next;
            ListNode* temp2 = oddEnd->next->next;
            oddEnd->next->next = temp1;
            evenEnd->next = temp2;
            oddEnd = oddEnd->next;
            evenEnd = evenEnd->next;
        } 
        return head;
    }
};