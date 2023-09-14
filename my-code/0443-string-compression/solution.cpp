class Solution {
public:
    int compress(vector<char>& chars) {
        //Just write algo according to given condition:
         string s="";
         int cnt=1;
         for(int i=1;i<chars.size();i++){
           if(chars[i]==chars[i-1]){
               cnt++;

           }
           else{
               s+=chars[i-1];
               if(cnt>1){
               string str = to_string(cnt);
               cout<<str<<endl;
                 s+=str;
               }
               cnt=1;
           }
         }
         s+=chars[chars.size()-1];
         if(cnt>1){
             string str = to_string(cnt);
             cout<<str<<endl;
             s+=str;
         }

         //NOW REPLACE KARNE KO BOLA HAI QUESTION ME:
         vector<char> delta;
         for(char ch : s){
             delta.push_back(ch);
         }
         chars = delta;
         delta.clear();
 


         return s.size();
    }
};
