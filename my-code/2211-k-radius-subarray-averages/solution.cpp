class Solution {
public:
     vector<int> ans;
    vector<int> getAverages(vector<int>& nums, int k) {
        
       
        int n = nums.size();
         vector<int> store(n,-1);
        if(n>=2*k+1){
        
        long long int sum=0;
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }


        for(int i=k;i<=n-k-1;i++){
            //cout<<"Store is "<<sum<<endl;
               store[i]=sum/(2*k+1);
               cout<<store[i]<<endl;
               sum-=nums[i-k];
               if(i+k+1<n){
               sum+=nums[i+k+1];
               }
        }
    
        }
        return store;
    }
};
