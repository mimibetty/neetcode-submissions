class MyHashMap {
private:
    struct Node {
        int key, value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    
    vector<Node*> buckets;
    int capacity;
    int size;
    const double LOAD_FACTOR_THRESHOLD = 0.75;
    
    int hash(int key) {
        // Mix high bits into low bits (like Java's HashMap)
        unsigned int h = key;
        h ^= (h >> 16);
        return h & (capacity - 1);  // Fast modulo (capacity is power of 2)
    }
    
    void resize() {
        int oldCapacity = capacity;
        vector<Node*> oldBuckets = buckets;
        
        // Double capacity
        capacity *= 2;
        buckets = vector<Node*>(capacity, nullptr);
        size = 0;
        
        // Rehash all entries
        for (int i = 0; i < oldCapacity; i++) {
            Node* curr = oldBuckets[i];
            while (curr != nullptr) {
                Node* next = curr->next;
                // Re-insert into new buckets
                int idx = hash(curr->key);
                curr->next = buckets[idx];
                buckets[idx] = curr;
                size++;
                curr = next;
            }
        }
    }
    
public:
    MyHashMap() : capacity(16), size(0) {
        buckets.resize(capacity, nullptr);
    }
    
    ~MyHashMap() {
        for (Node* head : buckets) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        
        // Check if key already exists
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;  // Update
                return;
            }
            curr = curr->next;
        }
        
        // Insert at head of chain (O(1))
        Node* newNode = new Node(key, value);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
        size++;
        
        // Check if resize needed
        if ((double)size / capacity > LOAD_FACTOR_THRESHOLD) {
            resize();
        }
    }
    
    int get(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        while (curr != nullptr) {
            if (curr->key == key) return curr->value;
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        Node* curr = buckets[idx];
        Node* prev = nullptr;
        
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    buckets[idx] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                size--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};