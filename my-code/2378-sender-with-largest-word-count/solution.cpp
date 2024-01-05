class Solution {
public:
    struct cmp{
        bool operator()(pair<string,int> &a,pair<string,int> &b) const{
            if(a.second==b.second){
                  return a.first>b.first;
            }
            return a.second>b.second;
        }
    };

    int number_of_msg(string &str){
        int counter=0;

        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                counter++;
            }
        }
        return counter+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        //do with priorit queue:
        unordered_map<string,int> mp;
        int n = messages.size();
        for(int i=0;i<n;i++){
            string msg = messages[i];
            string author = senders[i];
            int time = number_of_msg(msg);
            mp[author]+=time;
        }
       
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        
        for(auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->first,it->second});
            if(pq.size()>1){
                pq.pop();
            }
        }
        return pq.top().first;
         
    }
};
