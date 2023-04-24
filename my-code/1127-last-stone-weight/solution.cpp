class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
 
        int first,second;
        while(!pq.empty()){
            if(pq.size()==1){
                return pq.top();
            }
            int first=pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first!=second){
                pq.push(first-second);
            }
        }
        return 0;

    }
};
