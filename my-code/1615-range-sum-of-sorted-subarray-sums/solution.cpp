class Solution {
public: 
    const int mod = 1e9 + 7;
    void solve(vector<int> &arr,vector<int> &subarray){
         //generate all subarray:
         
          int n  = arr.size();
          for(int i = 0;i<n;i++){
               int sum=0;
               for(int j=i;j<n;j++){
                     sum+=arr[j];
                     subarray.push_back(sum);
               }
             
          }
        
        
    }
    
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
                     vector<int> subarray;
                     solve(nums,subarray);
                     sort(subarray.begin(),subarray.end());
                    
                     int sum=0;
                      for(int i = left-1;i<=right-1;i++){
                           sum = (sum%mod+(subarray[i]%mod))%mod;
                      }
                    return sum;
    }
};
