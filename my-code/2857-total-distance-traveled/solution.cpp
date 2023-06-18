class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        while(true){
            if(mainTank>=5){
                mainTank-=5;
                int val = 5*10;
                ans = ans+val;
                if(additionalTank>0){
                    mainTank++;
                    additionalTank--;
                }
            }
            else{
                break;
            }
        }
        int val = mainTank*10;
        return ans+val;
    }
};
