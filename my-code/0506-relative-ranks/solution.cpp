class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }

        int place=1;
        vector<string> result(n);
        while(!pq.empty()){
            int value = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(place==1){
                result[idx] = "Gold Medal";
            }
            else if(place==2){
                result[idx] = "Silver Medal";
            }
            else if(place==3){
                result[idx] = "Bronze Medal";
            }
            else{
              result[idx] = to_string(place); 
            }
            place++;
        }
        return result;
    }
};
