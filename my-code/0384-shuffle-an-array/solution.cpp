class Solution {
public:
    vector<int> real;
    vector<int> ans;
    Solution(vector<int>& nums) {
          real = nums;
          ans = real;
    }
    
    vector<int> reset() {
        return ans;
    }
    
    vector<int> shuffle() {
           int n = real.size();
         
           for(int i=n-1;i>=0;i--){
               int idx = rand()%n;
               swap(real[idx],real[i]);
           }
           return real;
    }
};


