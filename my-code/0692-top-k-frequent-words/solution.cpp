class Solution {
public:
    struct cmp{
        bool operator()(pair<string,int> &a,pair<string,int> &b) const{
            if(a.second == b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            mp[str]++;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq; //Image as simple to do what you want as like vector<string,int> vec:  always image that you are in vector and now for visublise priority queue rotate image of vector<int> by 180:
        for(auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->first,it->second});
            if(pq.size()>k){
                pq.pop();
            }
        }

       vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
