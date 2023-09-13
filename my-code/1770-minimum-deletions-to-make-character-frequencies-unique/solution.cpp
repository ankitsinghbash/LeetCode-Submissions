class Solution {
public:

    int solve(string s){
       vector<int> alpha(26,0);
       for(auto ch: s){
           alpha[ch-'a']++;
       }
       vector<int> store;
      
       for(int i=0;i<26;i++){
             if(alpha[i]!=0){
                 store.push_back(alpha[i]);
             }
       }
       sort(store.begin(),store.end(),greater<int>());
       int maxx = *max_element(store.begin(),store.end());

       int ans=0;
       for(int i=0;i<store.size();i++){ 
           cout<<store[i]<<endl;
           if(maxx>0){
            if(store[i]<maxx){
               maxx = store[i];
           }            
               
           if(store[i]>=maxx){
               ans+=(store[i]-maxx);
               maxx--;
           }
           }
           else{
               ans+=store[i];
           }

           
       }
       return ans;
    }


    int minDeletions(string s) {
        //greedy solve:
        return solve(s);
    }
};
