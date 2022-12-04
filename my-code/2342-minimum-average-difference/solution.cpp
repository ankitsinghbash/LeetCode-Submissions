class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
           
       vector<long long> ans;
       long long  total=0;
       for(long long i=0;i<nums.size();i++)
       {
         total+=nums[i];
       }
       
      
       long long currwind = 1;
       long long  currwindsum=0;
       while(currwind!=nums.size())
       {
         currwindsum+=nums[currwind-1];
         long long rest = total-currwindsum;
         
         
         
         long long  val1 = currwindsum/currwind;
         long long restdiv=nums.size()-currwind;
         long long  val2 = rest/restdiv;
         long long aver = abs(val1-val2);
         ans.push_back(aver);
         currwind++;
       }
       
       long long  last = total/nums.size();
       ans.push_back(last);
       
       long long mini=*min_element(ans.begin(),ans.end());
       for(long long i=0;i<ans.size();i++)
       {
         if(mini==ans[i])
         {
           return i;
         }
       }
       return -1;



    }
};
