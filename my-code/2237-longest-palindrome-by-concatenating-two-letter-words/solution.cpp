class Solution {
public:

   bool palindrome(string str,int start,int end){
       while(start<=end){
           if(str[start]!=str[end]){
               return false;
           }
           start++;
           end--;
       }
       return true;
   }

    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();++i){
            string str = words[i];
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            if(mp[rev]>0){
                 ans+=4;
                 mp[rev]--;
            }
            else{
                mp[str]++;
            }
        }

        for(auto it=mp.begin();it!=mp.end();++it){
            string str = it->first;
            if(palindrome(str,0,str.size()-1)==true){
                if(it->second>0){
                    ans+=2;
                    break;
                }
            }
        }
        return ans;
    }
};
