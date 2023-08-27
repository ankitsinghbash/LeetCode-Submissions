class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxx=0;
        vector<int> visited(nums.size(),false);
        for(int i=0;i<nums.size();i++){
           if(visited[i]==false){
              int j = i;
              int cnt=0;
              while(true){
                int value = nums[j];
                j=value;
                if(visited[j]==true){
                    break;
                }
                cnt++;
                visited[value]=true;   
            }

            maxx = max(maxx,cnt);
           }
            
        }
        return maxx;
    }
};
