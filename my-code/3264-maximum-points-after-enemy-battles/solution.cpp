class Solution {
public:
     typedef long long ll;
    long long maximumPoints(vector<int>& enemy, int e) {
        //dp work here"
        //But due to constraints not use dP:
        //use max heap:
        priority_queue<ll,vector<ll>> pq;
        ll mini = LLONG_MAX;

       for(ll i=0;i<enemy.size();i++) {
           pq.push(enemy[i]);
           mini=min(mini,(long long)enemy[i]);
        }

        ll points=0;
        if(points==0){
            
            if(mini>e){
                return 0;
            }
        }
        
        ll value = e/(mini);
        points+=value;
        ll rest = e%mini;   
        while(pq.size()>1){
            ll big = pq.top();
            pq.pop();
            rest+=big;
            points+=rest/mini; 
            rest = rest%mini;
            
        }
        return points;
        
    }
};
