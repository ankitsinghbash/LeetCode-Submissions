class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
         unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            string str = arr[i];
            mp[str]++;
        }
        
        
         int cnt=0;
         for(int i=0;i<arr.size();i++){
             string str = arr[i];
             if(mp[str]==1){
                 cnt++;
                 if(cnt==k){
                     return str;
                 }
             }
         }
        
        return "";
        
    }
};
