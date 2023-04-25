class Solution {
public:
   
   int solve(vector<int> &nums1,vector<int> &nums2,int s1,int s2){

     int l1 = nums1.size()*1;
     int r2 =nums2.size()*6;
     if(l1>r2){
         return -1;
     }

     int i=nums1.size()-1;
     int j=0;
     int cnt=0;
     while(i>=0 || j<nums2.size()){
         if(s1<=s2)break;
         int change1=-1;
         int change2=-1;
         if(i>=0){
             change1=abs(nums1[i]-1);
         }
         if(j<nums2.size()){
             change2=abs(6-nums2[j]);
         }
         if(change1>=change2){
             s1=s1-nums1[i]+1;
             i--;
         }
         else if(change1<change2){
             s2=s2-nums2[j]+6;
             j++;
         }
         cnt++;
     }
     return cnt;

   }




    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int s1=0;
        int s2=0;
        for(auto &x : nums1){
            s1+=x;
        }
        for(auto &y:nums2){
            s2+=y;
        }
        if(s1==s2){
            return 0;
        }
        if(s1>s2){
            return solve(nums1,nums2,s1,s2);
        }
        return solve(nums2,nums1,s2,s1);

    }
};
