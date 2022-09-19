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
         
         if(map.find(sum-target)!=map.end()) //means ager value mil gyi;
         {
             //value repeat hui to uski second value ko add karo;
             count+=map[sum-target];  //it give second value m[];
         }
         //if above find me nahi gya means to map me value daal ke one increase kar do:
         //if repeat value come in any case then map take it only one time and only increase the
         //second value so it directly count by the count variable;
         map[sum]++; 
     }
        return count;
    }
};
