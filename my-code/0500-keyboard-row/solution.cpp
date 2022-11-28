class Solution {
public:
    vector<string> ans;


   bool find(string &mystr , string &str)
   {
       for(int i=0;i<mystr.size();i++)
       {
           char ch = mystr.at(i);
           char ch1 = tolower(ch);
           int j=0;
           bool flag=true;
           while(j<str.size())
           {
               char ch2 = str.at(j);
               if(ch1==ch2)
               {
                   flag=false;
                   break;
               }
               j++;
           }
           if(flag==true)
           {
               return false;
           }
       }    
      return true;
     

   }



    vector<string> findWords(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string str1 = "qwertyuiop";
            string str2 = "asdfghjkl";
            string str3 = "zxcvbnm";
            string mystr  = words[i];
            bool check1  = find(mystr,str1);
            if(check1==true) ans.push_back(mystr);
            bool check2 = find(mystr,str2);
            if(check2==true) ans.push_back(mystr);
            bool check3  = find(mystr,str3);
            if(check3==true) ans.push_back(mystr);
        }
       return ans;
    }
};
