class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
     if(word1.size()!=word2.size()) return false;

      vector<int> w1(26,0);
      vector<int> w2(26,0);

      for(int i=0;i<word1.size();i++)    
      {
          w1[word1[i]-'a']++;   //give the count at sorted ordered at our position:
          w2[word2[i]-'a']++;
      }

      for(int i=0;i<26;i++)
      {
          if(w1[i]!=0&&w2[i]!=0&&w1[i]!=w2[i])
          {
            for(int j=i+1;j<26;j++)
            {
              if(w1[j]==w2[i])
              {
                  //swap:
                  swap(w1[j],w1[i]);
               }
           }
          }
      }


      for(int i=0;i<26;i++)
      {
          if(w1[i]!=w2[i])
          {
              return false;
          }
      }
     
      return true;

       


    }
};
