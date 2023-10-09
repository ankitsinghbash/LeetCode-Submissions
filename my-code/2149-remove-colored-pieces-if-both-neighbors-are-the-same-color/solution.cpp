class Solution {
public:
    bool winnerOfGame(string colors) {
        //Greedy  which has maximum 3 consicutive win the game:
        int alicacnt=0;
        int bobcnt=0;
        for(int i=1;i<colors.size()-1;i++){
            char prev = colors[i-1];
            char curr = colors[i];
            char next = colors[i+1];

            if(prev=='A' && curr=='A' && next=='A'){
                alicacnt++;
            }
            else if(prev=='B' && curr=='B' && next=='B'){
                bobcnt++;
            }
        }
        return alicacnt-bobcnt>0;
    }
};
