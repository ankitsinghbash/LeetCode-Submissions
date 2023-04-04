class Solution {
public:
    vector<int> partitionLabels(string s) {
       //using map:
       unordered_map<char,int> mp;
       for(int i=0;i<s.size();++i){
           mp[s[i]]=i;   //store the lastest value of duplicate value:
       }
    
       vector<int> ans;
       int maxx=0;
       int last=0;
       for(int i=0;i<s.size();i++){
           maxx=max(maxx,mp[s[i]]);
           if(i==maxx){
               ans.push_back(i-last+1);
               last=i+1;
           }
       }
       return ans;


        //using hasmap:
        // vector<int> arr(26);
        // for(int i=0;i<s.size();i++){
        //     arr[s[i]-'a']=i;
        // }

        // vector<int> ans;
        // int maxx=0;
        // int last=0;
        // for(int i=0;i<s.size();i++){
        //     maxx=max(maxx,arr[s[i]-'a']);
        //     if(i==maxx){
        //         ans.push_back(i-last+1);
        //         last=i+1;
        //     }
        // }
        // return ans;
    }
};
