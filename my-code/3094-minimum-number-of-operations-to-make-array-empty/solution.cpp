class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
  
        int ans=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            int time = it->second;
            //7 -> 2,2,3
            //9->3,3,3
            //6->2,2,2 and 3,3(taken):
            if(time==1){
                return -1;
            }
            else if(time%3==0){
                int x = time/3;
                ans+=x;
            }
            else{
                if(time%3==1){   //odd
                   int x = time/3;
                   x=x-1;
                   ans+=x;
                   int rest = time-x*3;
                   ans+=rest/2;
                 }
                else if(time%3==2){
                        int x = time/3;
                        ans+=x;
                        int rest = time-x*3;
                        ans+=rest/2;
                    }
                }
            }
            if(ans==0){
            return -1;
        }
        return ans;
        }
      
    
};
