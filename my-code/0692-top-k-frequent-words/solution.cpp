class Cmp{
    public:
    bool operator()(pair<string,int> &a,pair<string,int> &b){
        if(a.second==b.second){
              return a.first>b.first;
        }
        return a.second<b.second;
            
    }
};

class Solution {
public:
    typedef pair<string,int> P;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &v : words){
            mp[v]++;
        }

        priority_queue<P,vector<P>,Cmp> pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->first,it->second});
        }

        vector<string> ans;
        while(pq.size()>0 && k--){
            pair<string,int> Pair = pq.top();
            pq.pop();
            ans.push_back(Pair.first);
        }
        return ans;

    }
};
