class Solution {
public:
   
    vector<int> countBits(int n) {
        vector<int> sol;
    int temp=n;
     while(temp>=0)
     {
      n = temp;
     vector<int> v;
     while(0<n)  
     {    
       int val=n%2;
       v.push_back(val);
       n= n/2;  
      }    
     reverse(v.begin(),v.end());
   
     int counter=0;
     for(int i=0;i<v.size();i++)
     {
       if(v[i]==1)
      {
        counter++;
      }
    }
    sol.push_back(counter);
    v.clear();
    temp--;
    }
     reverse(sol.begin(),sol.end());
    return sol;

    }
   
};
