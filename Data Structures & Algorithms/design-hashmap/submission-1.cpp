class MyHashMap {
private:
    static const int BUCKET_COUNT = 1009;  // Prime number
    vector<list<pair<int, int>>> buckets;  // Array of linked lists
    
    // Hash function
    int hash(int key) {
        return key % BUCKET_COUNT;
    }
    
    // Helper: find iterator to key in a bucket (or end() if not found)
    list<pair<int, int>>::iterator findKey(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) return it;
        }
        return bucket.end();
    }
    
public:
    MyHashMap() : buckets(BUCKET_COUNT) {}
    
    void put(int key, int value) {
        int idx = hash(key);
        auto it = findKey(key);
        
        if (it != buckets[idx].end()) {
            it->second = value;  // Update existing
        } else {
            buckets[idx].push_back({key, value});  // Insert new
        }
    }
    
    int get(int key) {
        int idx = hash(key);
        auto it = findKey(key);
        return (it != buckets[idx].end()) ? it->second : -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = findKey(key);
        if (it != buckets[idx].end()) {
            buckets[idx].erase(it);
        }
    }
};