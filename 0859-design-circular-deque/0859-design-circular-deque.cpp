
class DLLNode{
public : 
    int val;
    DLLNode* next;
    DLLNode* prev;

    
    DLLNode(int val){
        this->val = val;
        next = prev = NULL;
    }
};

class MyCircularDeque {
public:
    int size;
    int k;
    DLLNode* head;
    DLLNode* tail;
    MyCircularDeque(int k) {
        head = new DLLNode(-1);
        tail = new DLLNode(-1);
        head->next = tail;
        tail->prev = head;
        this->k = k;
        this->size = 0;
    }
    
    bool insertFront(int val) {
        if(size == k)
            return false;
        DLLNode* node = new DLLNode(val);
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
        return true;
    }
    
    bool insertLast(int val) {
        if(size == k)
            return false;
        DLLNode* node = new DLLNode(val);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0)
            return false;
        DLLNode *curr = head->next;
        head->next->next->prev = head;
        head->next = head->next->next;
        delete curr;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0)
            return false;
        DLLNode *curr = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        delete curr;
        size--;
        return true;
    }
    
    int getFront() {
        return head->next->val;
    }
    
    int getRear() {
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

 