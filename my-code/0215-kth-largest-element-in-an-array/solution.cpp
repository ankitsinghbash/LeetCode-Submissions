class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int,vector<int>,greater<int> > p1;
         for(int i=0;i<k;i++){
             p1.push(nums[i]);
         } 

         for(int i=k;i<nums.size();i++){
             int val = p1.top();
             if(val<=nums[i]){
                 p1.pop();
                 p1.push(nums[i]);
             }
         }
         return p1.top();
    }
};


// sort(nums.begin(),nums.end());
//         int j=nums.size()-1;
//         int last;
//         while(k--){
//             last = nums[j];
//             j--;
//         }  
//         return last;
