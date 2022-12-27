class Solution {
public:
    int lastStoneWeight(vector<int>& stone) {
    priority_queue<int> qu; 
    for(int i=0;i<stone.size();i++){
        qu.push(stone[i]);
    }
    int first,second;
    while(!qu.empty()){
        if(qu.size()==1){
            return qu.top();
        }
         first = qu.top();
         qu.pop();
         second = qu.top();
         qu.pop();
         if(first!=second){
             qu.push(first-second);
         }
    }
    return 0;
    }

};
