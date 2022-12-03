class Solution {
public:

   static bool cmp(pair<char,int> &a,pair<char,int> &b)
   {
       return a.second>b.second;
   }


    string frequencySort(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++)
        {
            char ch = s.at(i);
            v.push_back(ch);
        }

        vector<pair<char,int>> v_pair;
        int n=v.size();
   vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
   {
     if(visited[i]!=true)
     {
       int counter=0;
       for(int j=0;j<n;j++)
       {
         if(v[i]==v[j])
         {
           counter++;
           visited[j]=true;
         }
         
       }
       v_pair.push_back({v[i],counter});
     }
   }
   
   sort(v_pair.begin(),v_pair.end(),cmp);
   
   
   
   string ans;
   for(int i=0;i<v_pair.size();i++)
   {
     int times = v_pair[i].second;
     while(times!=0)
     {
       ans+=v_pair[i].first;
       times--;
     }
   }

      return ans;
    }
};
