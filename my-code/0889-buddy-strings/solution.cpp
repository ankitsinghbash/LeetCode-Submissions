class Solution {
public:
    bool buddyStrings(string s, string goal) {
      

       unordered_map<char,int> mp;
       for(int i=0;i<s.size();i++){
           mp[s[i]]++;
       }
 
       vector<int> v;
       int cnt=0;
       for(int i=0;i<s.size();i++){
           if(s[i]!=goal[i]){
               v.push_back(i);
               cnt++;
           }
       }
     
       for(auto x: v){
           cout<<x<<endl;
       }
     
       if(s==goal){
           for(auto it = mp.begin();it!=mp.end();it++){
               if(it->second>1){
                   return true;
               }
           }
           return false;
       }

       if(cnt==2){
            string str = s;
            swap(str[v[0]],str[v[1]]);
            if(str==goal){
                return true;
            }
            return false;
       }
       return false;
      

    }
};
