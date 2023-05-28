class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //Greedy approach Game theory:
         //another approch odd ,even positon technique not use here but important in game theory:
        //If alice max taken kare then bob min taken kar game theory concep say that:
        int alice=0,bob=0;
        int low=0;
        int high=piles.size()-1;
        while(low<high){
            alice+=max(piles[low],piles[high]);
            bob+=min(piles[low],piles[high]);
            low++;
            high--;
        }
        return alice>bob;
    }
};
