class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
           //greedy and well binary serach:
           sort(players.begin(),players.end());
           sort(trainers.begin(),trainers.end());
           int n = players.size();
           int m = trainers.size();
           int left=0;
           int right=0;
           int ans=0;
           while(left<n && right<m){
                  if(players[left]<=trainers[right]){
                    left++;
                    right++;
                    ans++;
                  }
                  else{
                     right++;
                  }
           }
           return ans;
    }
};


