class Solution {
public:
    int longestPalindrome(string s) {
        //maxx_value of odd + all value of even:
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
         
        int total=0;
        bool first_odd=true;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second%2!=0){
                if(first_odd==true){
                     total+=it->second;
                     first_odd=false;
                }
                else{
                    total+=it->second-1;
                }
            }
            else{
                total+=it->second;
            }
        }
        
        return total;
         
    }
}; 
