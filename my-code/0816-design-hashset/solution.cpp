class MyHashSet {
public:
    int M;
    vector<list<int>> hashing;
    MyHashSet() {
        M = 10001; //let M=15000
        hashing = vector<list<int>>(M,list<int>{});  //given the size of list taken 10001*10001 matrix size around but give an empty linkedlist{} is most prefiable as give the linked list size:
    }
    
    void add(int key) {
        int index = key%M;
        auto itr = find(hashing[index].begin(),hashing[index].end(),key);
        if(itr==hashing[index].end()){
        hashing[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = key%M;
        auto itr = find(hashing[index].begin(),hashing[index].end(),key);
        if(itr!=hashing[index].end()){
            hashing[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index = key%M;
        auto itr = find(hashing[index].begin(),hashing[index].end(),key);
        if(itr!=hashing[index].end()){
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
