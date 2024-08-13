class KthLargest {
public:
    vector<int> arr;
    int kth;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
        }
        
        kth = k;
        
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>kth){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
       
         pq.push(val);
         if(pq.size()>kth){
             pq.pop();
             
         }
         int ans = pq.top();
       
        return ans;
        
       
       
       
         
    
      
      
        
      
         
      
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//2,3,4,4,5,5,8,9,10
//means duplicate is not allow:
