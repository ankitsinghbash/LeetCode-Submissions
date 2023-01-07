class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //1,1,2,3,5,6
        sort(costs.begin(),costs.end());
        int counter=0;
        for(int i=0;i<costs.size();i++)
        {
           
            coins=coins-costs[i];
            if(coins>=0){
            counter++;
            }
            if(coins<0){
                return counter;
            }
        }
        return counter;
    }
};
