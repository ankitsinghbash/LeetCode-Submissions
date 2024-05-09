class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //optimize way solution:
        long long ans = 0;
        int n=happiness.size();
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(happiness[i]);
        }
 
        int rate_of_decrement=0;
        while(k--){
            int value = pq.top();
            pq.pop();
            if(value-rate_of_decrement>0){
               ans+= (value-rate_of_decrement);
            }
            rate_of_decrement++;
        }
        return ans;
    }
};
