class Solution {
public:
   void solve(vector<int> &cookies,int k,int &result,vector<int> &box,int idx){
       if(idx>=cookies.size()){
           int max_value = *max_element(box.begin(),box.end());
           result = min(result,max_value);
           return;
       }



       for(int i=0;i<k;i++){
           box[i]+=cookies[idx];
           solve(cookies,k,result,box,idx+1);
           box[i]-=cookies[idx];
       }
  

   }




    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> box(k,0);
        int result = INT_MAX;
        solve(cookies,k,result,box,0);
        return result;
    }
};
