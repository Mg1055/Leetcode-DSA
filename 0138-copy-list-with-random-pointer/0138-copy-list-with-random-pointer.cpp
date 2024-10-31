/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) 
            return head;

        // insert copy nodes in between
        Node* temp = head;
        while(temp != NULL){
            Node* nextElement = temp->next;
            temp->next = new Node(temp->val);  
            temp->next->next = nextElement;         
            temp = nextElement;         
        }
    
        // connect random pointers
        temp = head;
        while(temp != NULL){
            if(temp->random != NULL)
                temp->next->random = temp->random->next; 
            temp = temp->next->next;   
        }

        // seperate 2 lists and get head of copied list
        temp = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;             

        while(copy->next != NULL){
            temp->next = temp->next->next;
            temp = temp->next;

            copy->next = copy->next->next;
            copy = copy->next;
        }
        temp->next = temp->next->next;

        return copyHead;
    }
};