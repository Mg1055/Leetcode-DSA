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
        ListNode *oe = head, *ee = head->next;
        while(ee != NULL && ee->next != NULL){
            ListNode* temp1 = oe->next;
            oe->next = ee->next;
            ListNode* temp2 = oe->next->next;
            oe->next->next = temp1;
            ee->next = temp2;
            oe = oe->next;
            ee = ee->next;
        } 
        return head;
    }
};