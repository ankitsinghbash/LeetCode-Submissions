class Solution {
public:
    typedef pair<long,long> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int> store(n,0);
        priority_queue<P,vector<P>,greater<P>> pq;
        priority_queue<int,vector<int>,greater<int>> visited;
      
        for(int i=0;i<n;i++){
            visited.push(i);
        }

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0];
            int end =  meetings[i][1];

            while(!pq.empty() && pq.top().first<=start){ //IF current time is greater then prev elements end time:
                int room_no = pq.top().second;
                pq.pop();
                visited.push(room_no);
            }
             
            if(!visited.empty()){     //If room is avaible:
                int room_no = visited.top();
                visited.pop();
                pq.push({end,room_no});
                store[room_no]++;
            }
            else{
                //NO room is avaible:
                long long endtime = pq.top().first;
                int room_no = pq.top().second;
                pq.pop();
                pq.push({endtime+(end-start),room_no});
                store[room_no]++;
            }
        }
        
        int resultRoom = -1;
        int maxUse     = 0;  
        for(int room = 0; room < n; room++) {
            if(store[room] > maxUse) {
                maxUse = store[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};
