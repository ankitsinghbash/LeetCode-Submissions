class Solution {
public:

  int binary_search(vector<int> &pos,long long success,long long val){
         long long low  = 0;
         long long high = pos.size()-1;
         int possible=pos.size();
         
         
         while(low<=high){
             int mid = low+(high-low)/2;
             long long data = (long long)(pos[mid])*val;
             if(data>=success){

                  possible=mid;
                  high = mid-1;
             }
             else if(data<success){
                 low= mid+1;
             }
         }
         return pos.size()-possible;
  }


    vector<int> successfulPairs(vector<int>& spells, vector<int>& pos, long long success) {
        vector<int> ans;
        sort(pos.begin(),pos.end());
        for(int i=0;i<spells.size();i++){
            long long  val = spells[i];
         
            int size = binary_search(pos,success,val);
            
                
         
           
                ans.push_back(size);
            
        }
        return ans;
    }
};
