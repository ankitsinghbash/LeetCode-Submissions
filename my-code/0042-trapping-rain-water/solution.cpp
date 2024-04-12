class Solution {
public:
    int trap(vector<int>& height) {
        //Question based on next greater element:
         int n = height.size();
         vector<int> right(n);
         vector<int> left(n);

         int maxx = INT_MIN;
         for(int i=0;i<n;i++){
            if(height[i]>maxx){
                maxx = height[i];
            }
            left[i] = maxx;
         }

         int maxx1 = INT_MIN;
         for(int i=n-1;i>=0;i--){
              if(height[i]>maxx1){
                maxx1 = height[i];
              }
              right[i] = maxx1;
         }
 
         int trap=0;
         for(int i=0;i<n;i++){
            int val = min(left[i],right[i])-height[i];
            trap+=val;
         }
         return trap;
    }
};
