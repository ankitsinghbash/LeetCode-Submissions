class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         //method 1 using unordered_map;
         unordered_map<int,int> mp;
         for(int i=0;i<nums.size();i++)
         {
             mp[nums[i]]++;
         }

         int counter=0;
         unordered_map<int,int> :: iterator it;
         for(it=mp.begin();it!=mp.end();it++)
         {
             if(k==0)
             {
                if(it->second>=2)
                {
                    counter++;
                }
             }
             else if(mp.find(it->first+k)!=mp.end())
             {
                 counter++;
             }
         }
         return counter;

    }
};


//method-2;
/*Run but time take more: and lenthy:
 bool checkpair(vector<pair<int,int>> &vec_pair,int val1,int val2)
   {
       for(int i=0;i<vec_pair.size();i++)
       {
           if(vec_pair[i].first==val1&&vec_pair[i].second==val2)
           {
               return true;
           }
       }
       return false;
   }

    int findPairs(vector<int>& nums, int k) {
       vector<pair<int,int>> vec_pair;
       sort(nums.begin(),nums.end());

       int counter=0;
       for(int i=1;i<nums.size();i++)
       {
           int j=i-1;
           while(j>=0)
           {
               if(nums[i]-nums[j]>k)
               {
                   break;
               }

               if(nums[i]-nums[j]==k)
               {
                   //check pair is exist in the vec_pair or not:
                 
                   int val1 = nums[i];
                   int val2 = nums[j];
                   //auto pairs = {val1,val2};
                   bool ans = checkpair(vec_pair,val1,val2);
                   if(ans==false)
                   {
                       counter++;
                   }
                   vec_pair.push_back(make_pair(val1,val2));

               }
               j--;
           }
       }
       return counter;

*/
