class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> qu;
        for(int i=1;i<=9;i++){
            qu.push(i);
        }
 
        vector<int> ans;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                int val = qu.front();
                int last = val%10;
                qu.pop();

                if(low<=val && val<=high){
                    ans.push_back(val);
                }

                if(last==9){
                    continue;
                }
                qu.push(val*10+last+1);
               
            }
        }

        return ans;
    }
};
