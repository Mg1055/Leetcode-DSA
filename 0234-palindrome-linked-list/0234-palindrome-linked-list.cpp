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
    
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *prev = NULL, *nxt = head, *curr = head; // Iterative
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true; 
        
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;  
            fast = fast->next->next;  
        }
        
        ListNode* newHead = reverseLinkedList(slow->next);
        ListNode* first = head;  
        ListNode* second = newHead; 

        while (second != NULL) {
            if (first->val != second->val) {
                reverseLinkedList(newHead);  
                return false;
            }
            first = first->next; 
            second = second->next;  
        }
        
        reverseLinkedList(newHead);  
        return true;  
    }
};