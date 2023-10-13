class MapSum {
public:
    //solve using trie:
    vector<pair<string,int>> v;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                v[i].second=val;
                return;
            }
        }
        v.push_back({key,val});
    }


    bool check(string &str,string &v_str){
        if(v_str.size()<str.size()){
            return false;
        }
 
        int i=0;
        int j=0;
        while(i<str.size()){
            if(str[i]==v_str[j]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int sum(string prefix) {
        string str = prefix;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            string v_str = v[i].first;
            if(check(str,v_str)==true){
                  cout<<"true"<<"string"<<v_str<<endl;
                  cnt+=v[i].second;
            }
        }
        return cnt;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
