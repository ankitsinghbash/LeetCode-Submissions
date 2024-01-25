class Solution {
public:
  const int mod = 1e9+7;
   vector<int> solve_left(vector<int> &arr){
          //
          vector<int> ans(arr.size());
          stack<int> st;
         // st.push(0);
          //ans[0]=1;
          for(int i=0;i<arr.size();i++){
                  while(!st.empty()  && arr[i]<=arr[st.top()]){
                      st.pop();
                  }
                  if(st.empty()){
                      ans[i] = i+1;
                  }
                  else{
                      ans[i]=i-st.top();
                  }
                  st.push(i);       
          }
          
          return ans;
   } 
   vector<int> solve_right(vector<int> &arr){
        vector<int> ans(arr.size());
        int n = arr.size();
       // ans[n-1]=1;
        stack<int> st;
      //  st.push(n-1);
        for(int i=n-1;i>=0;i--){
               while(!st.empty() && arr[i]<arr[st.top()]){
                   st.pop();
               }
               if(st.empty()){
                   ans[i] = n-i;
               }
               else{
                   ans[i] = st.top()-i;
               }
               st.push(i);
        }
        return ans;
   }


    int sumSubarrayMins(vector<int>& arr) {
        vector<int> first = solve_left(arr);
        vector<int> second = solve_right(arr);
        long long int sum=0;
        for(int i=0;i<first.size();i++){
            int val1 = first[i];
            int val2 = second[i];
            long long totalway = val1*val2;
            long long totalsum = arr[i]*totalway;
            sum = (sum+totalsum)%mod;
        }
        return static_cast<int>(sum % 1000000007);
    }
};
