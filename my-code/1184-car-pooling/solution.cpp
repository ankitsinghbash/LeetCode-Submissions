class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //using Hashing:
        vector<int> store(1001,0);
        for(int i=0;i<trips.size();++i){
            int val = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            for(int j=start;j<end;j++){
                store[j]+=val;
            }
        }
        
        for(int i=0;i<store.size();++i){
            if(store[i]>capacity){
                return false;
            }
        }
        return true;
    }
};
