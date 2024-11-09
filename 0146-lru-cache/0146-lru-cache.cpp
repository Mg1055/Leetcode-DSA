class LRUCache {
public:

    class DLLNode {
        public:
            int key;
        int val;
        DLLNode* next;
        DLLNode* prev;
        DLLNode(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    DLLNode* head = new DLLNode(-1, -1);
    DLLNode* tail = new DLLNode(-1, -1);

    int cap;
    int size;
    unordered_map<int, DLLNode*>mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(DLLNode* node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLLNode* node) {
        DLLNode* preNode = node->prev;
        DLLNode* postNode = node->next;

        preNode->next = postNode;
        postNode->prev = preNode;
    }

    void moveToFront(DLLNode* node) {
        removeNode(node);
        addNode(node);
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        DLLNode* node = it->second;
        moveToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()){
            DLLNode* node = it->second;
            node->val = value;
            moveToFront(node);
        }
        else{
            size++;
            DLLNode* newNode = new DLLNode(key, value);
            mp[key] = newNode;
            addNode(newNode);

            if(size > cap){
                DLLNode* tailNode = tail->prev;
                removeNode(tailNode);
                mp.erase(tailNode->key);
                delete tailNode;
                size--;
            }
        }
    }
};