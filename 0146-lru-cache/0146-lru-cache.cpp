class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key,int val){
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        head->next = newNode;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void delNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }

    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            Node* res = mp[key];
            int ans = res->val;

            mp.erase(key);
            delNode(res);
            addNode(res);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            delNode(curr);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */