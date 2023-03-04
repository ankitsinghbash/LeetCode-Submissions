class Solution {
public:
    int splitNum(int n) {
       
    vector<int> v;
    while(n!=0){
      int rem = n%10;
      n=n/10;
      v.push_back(rem);
    }
    sort(v.begin(),v.end());
    
    string str1="";
    for(int i=0;i<v.size();i=i+2){
      str1+=to_string(v[i]);
    }
   
    string str2="";
    for(int i=1;i<v.size();i=i+2){
      str2+=to_string(v[i]);
    }
    
    int val = stoi(str1)+stoi(str2);
        return val;
    }
};
