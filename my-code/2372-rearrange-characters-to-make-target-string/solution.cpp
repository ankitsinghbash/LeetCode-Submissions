class Solution {
public:
    int rearrangeCharacters(string s, string target) {
       unordered_map<char,int> mp;
       for(char ch : s){
           mp[ch]++;
       }

       int total=0;
       while(true){
           bool flag=false;
           for(char ch : target){
               mp[ch]--;
               if(mp[ch]<0){
                   flag=true;
                   break;
               }
           }
           if(flag==true) break;
           if(flag==false)  total+=1;
       }
       return total;


    }
};
