class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix_xor(n);
        int curr=arr[0];
        prefix_xor[0]=arr[0];
        for(int i=1;i<n;i++){
             curr = arr[i]^curr;
             prefix_xor[i]=curr;
        }
 
        int m = queries.size();
        vector<int> store(m);
        for(int i=0;i<m;i++){
            int left = queries[i][0];
            int right = queries[i][1];

            if(left==right){
                store[i] = arr[left];
            }
            else{
                int val1 = prefix_xor[right];
                int val2=0;
                if(left>0){
                  val2 = prefix_xor[left-1];
                }
                 int total = val1^val2;
                store[i] = total;
            }
        }
        return store;
    }
};
