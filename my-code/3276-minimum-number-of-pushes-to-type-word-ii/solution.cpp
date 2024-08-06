class Solution {
public:
    int minimumPushes(string word) {
         vector<int> alpha(26,0);
         for(int i=0;i<word.size();i++){
             alpha[word[i]-'a']++;
         }
        
        sort(alpha.begin(),alpha.end(),greater<int>());
        
        
        int total_cost=0;
        int cnt=1;
        for(int i=0;i<26;i++){
             int time = alpha[i];
             
             if(cnt<=8){
                 total_cost+=time*1;
             }
            else if(cnt>8 && cnt<=16){
                 total_cost+=time*2;
            }
            else if(cnt>16 && cnt<=24){
                total_cost+=time*3;
            }
            else{
                 total_cost+=time*4;
            }
            cnt++;
           
        }
        return total_cost;
        
    }
};
