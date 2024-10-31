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
        Node* curr = head;
        unordered_map<Node*, Node*> um;
        while(curr != NULL){
            Node* newNode = new Node(curr->val);
            um[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while(curr != NULL){
            Node *copyNode = um[curr];
            copyNode->next = um[curr->next];
            copyNode->random = um[curr->random];
            curr = curr->next;
        }

        return um[head];
    }
};