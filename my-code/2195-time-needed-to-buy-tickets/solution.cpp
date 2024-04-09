class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //brute force method:
        int total=0;
        while(tickets[k]!=0){
             int cnt=0;
             for(int i=0;i<tickets.size();i++){
                 if(tickets[i]>0){
                    cnt++;
                    tickets[i]--;
                 }
                 if(tickets[k]==0){
                    break;
                 }
             }
             total+=cnt;
        }
        return total;
    }
};
