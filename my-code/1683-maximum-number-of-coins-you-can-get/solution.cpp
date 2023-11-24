class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int total=0;
        sort(piles.begin(),piles.end());
        int i=0;
        int j=piles.size()-2;
        int k = piles.size()-1;
        while(i<j){
            total+=piles[j];
            j-=2;
            k-=2;
            i++;
        }
        return total;
    }
};
