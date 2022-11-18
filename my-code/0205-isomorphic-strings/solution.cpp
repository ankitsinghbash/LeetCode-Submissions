class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
     int n=str1.size();
     int m=str2.size();
     if(n!=m) return false;

    map<char,bool>two;
    map<char,char>umap; 

    for(int i=0;i<n;i++)
    {
     if(!umap[str1[i]])
      {
         if(!two[str2[i]])
          {
            umap[str1[i]]=str2[i];
            two[str2[i]]=1;
           }
          else
          {
            return false;
          }
      }
      else
      {
        if(umap[str1[i]]!=str2[i]){
        return false;
        }
       }      
    }

    return true;

    }
};
