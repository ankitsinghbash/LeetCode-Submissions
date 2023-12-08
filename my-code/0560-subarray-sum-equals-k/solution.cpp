class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     
        int count=0;
      int n=nums.size();
      unordered_map<int,int> map;
      int target = k;
     int sum=0;  //initilize sum=0 and start each value of arr at prefix:
     for(int i=0;i<n;i++)
     {
         sum+=nums[i];
         if(sum==target)
         {
             count++;
         }
         
         if(map.find(sum-target)!=map.end())
         {
             count+=map[sum-target];   //total sum pe target remove karne ke baad jo aya hai add uthna time count:
             //basically sum-jo map me aya == target so how many time this happen add to count:
         }
        
         map[sum]++; 
     }
        return count;
    }
};

