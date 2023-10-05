class MyHashMap {
public:
   typedef pair<int,int> P;
    vector<list<P>> v;
    MyHashMap() {
        int M = 10001;
        v = vector<list<P>>(M,list<P>());
    }
    
    void put(int key, int value) {
        int idx = key%10001;
        auto &chain = v[idx];
        for(auto it=chain.begin();it!=chain.end();it++){
            pair<int,int> &p = *it;
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        chain.emplace_back(key,value);  //you use direct by emplace_back() function:
       // chain.push_back({key,value}); //why emplace_back work and push_back not work
    }
    
    int get(int key) {
        int idx  = key%10001;
        auto &chain = v[idx];
        for(auto it = chain.begin();it!=chain.end();it++){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = key%10001;
        auto &chain = v[idx];
        for(auto it = chain.begin();it!=chain.end();++it){
            pair<int,int> &p = *it;
            if(p.first==key){
                chain.erase(it);
                return;
            }
        }
    }
};
