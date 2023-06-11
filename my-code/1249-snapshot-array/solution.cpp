class SnapshotArray {
public:
    vector< vector<pair<int,int> > >v;
    int id;
    SnapshotArray(int length) {
        v.resize(length);
        id=-1;
        for(int i=0;i<length;i++)
        {
            v[i].push_back({id,0});
        }
    }
    
    void set(int index, int val) {
        v[index].push_back({id,val});
    }
    
    int snap() {
        id++;
        return id;
    }
    
    int get(int index, int snap_id) {
        int l=0,r=v[index].size()-1;
        int ans=0;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            if(v[index][mid].first<snap_id)
            {
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return v[index][ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
