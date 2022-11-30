class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        unordered_map<int,int> :: iterator it;

        set<int> stt;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(stt.find((*it).second)!=stt.end())
            {
                return false;
            }
            else
            {
                stt.insert((*it).second);
            }
        }
        return true;
    }
};
