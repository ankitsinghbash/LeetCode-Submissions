class MyHashSet {
public:
    vector<vector<int>> v;
    int M;
    MyHashSet() {
         M=10001;
         v = vector<vector<int>>(M,vector<int>{});
    }
    
    void add(int key) {
        int idx = key%M;
        auto it = find(v[idx].begin(),v[idx].end(),key);
        if(it==v[idx].end()){
            v[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = key%M;
        auto it = find(v[idx].begin(),v[idx].end(),key);
        if(it!=v[idx].end()){
            v[idx].erase(it);
        }
    }
    
    bool contains(int key) {
         int idx = key%M;
        auto it = find(v[idx].begin(),v[idx].end(),key);
        if(it!=v[idx].end()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
