class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       //as generarilze formula k-1 element only with [n/k];
       int major1=0;
       int major2=0;
       int cnt2=0;
       int cnt1=0;
       for(int i=0;i<nums.size();i++){
           if(major1==nums[i]){
               cnt1++;
           }
           else if(major2==nums[i]){
               cnt2++;
           }
           else if(cnt1==0){
               major1=nums[i];
               cnt1=1;
           }
           else if(cnt2==0){
               major2=nums[i];
               cnt2=1;
           }
           else{
               cnt1--;
               cnt2--;
           }
       }


       cnt1=0;
       cnt2=0;
       //verification step means major hoga bhi nahi(Maximum Only 2 element get major):
       for(int i=0;i<nums.size();i++){
           if(nums[i]==major1){
               cnt1++;
           }
           else if(nums[i]==major2){
               cnt2++;
           }
       }
       int n = nums.size();
       vector<int> result;
       if(cnt1>floor(n/3)){
           result.push_back(major1);
       }
       if(cnt2>floor(n/3)){
           result.push_back(major2);
       }
       return result;

    }
};
