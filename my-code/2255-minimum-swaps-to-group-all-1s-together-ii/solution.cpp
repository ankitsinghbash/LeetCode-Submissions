class Solution {
public:
    int minSwaps(vector<int>& nums) {
            //I can use the concept of sliding window:
            //iterator in arr by using sliding window of size  = total_number of 1's and check how many 1's is required to make this window as a contineouly 1:
           
            vector<long long> newarr(nums.begin(),nums.end());
            int totalone=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==1){
                    totalone++;
                }
                newarr.push_back(nums[i]);
            }
        
            int n = newarr.size();
            vector<long long> pre_cnt(n,0);
            int cnt=0;
            for(int i=0;i<n;i++){
                if(newarr[i]==1){
                     cnt++;
                }
                pre_cnt[i] = cnt;
            }


        
     


             
            

            int start = totalone-1;
            int mini = INT_MAX;
            
            if(totalone==0) return 0;
        
            for(int i=start;i<n;i++){
                if(i-totalone>=0){
                  int zero = pre_cnt[i]-pre_cnt[i-totalone];
                  int restzero = totalone-zero;
                  mini = min(mini,restzero);
                }
                else{
                  int zero = pre_cnt[i];
                  int restzero = totalone-zero;
                  mini = min(mini,restzero);
                }
            }
            return mini;


        
        
    }
};
