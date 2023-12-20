class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        //smallest and secondsmallest:
        int mini  = INT_MAX;
        int second_mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                second_mini = mini;
                mini  = prices[i];
            }
            else{
                //prices[i]>mini:
                second_mini = min(second_mini,prices[i]);
            }
        }
        int val = mini+second_mini;
        if(money-val>=0){
            return money-val;
        }
        return money;
    }
};
