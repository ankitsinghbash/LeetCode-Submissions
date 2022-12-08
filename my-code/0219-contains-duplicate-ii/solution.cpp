class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //any number which which is lesser then or equal to k:
        //and repeat two time hence true else false:
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        map<int,int> :: iterator it;

         //store indexing:
        for(it=mp.begin();it!=mp.end();it++){
            if((*it).second>=2){
                //first index:
                 vector<int> v;
                 int val = (*it).first;
                 for(int i=0;i<nums.size();i++){
                     if(val==nums[i]){
                         v.push_back(i);
                     }
                 }
                 
                 for(int i=1;i<v.size();i++){
                     if(v[i]-v[i-1]<=k) return true;
                 }

            }
        }
        return false;

      

    
        
    }
};
