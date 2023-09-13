class Solution {
public:
    vector<int> partitionLabels(string s) {
        //Now solve this greedy:
        unordered_map<char,int> last_occur;
        for(int i=0;i<s.size();i++){
            last_occur[s[i]]=i;
        }
  
        vector<int> ans;
        int j=0;
        while(j<s.size()){
            int i = j;
            int skip = last_occur[s[j]];
            while(i<=skip){
               skip = max(skip,last_occur[s[i]]);
               i++;
            }
            ans.push_back(i-j);
            j = i;
        }
        return ans;

    }
};
