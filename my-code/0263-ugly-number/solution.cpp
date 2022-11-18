class Solution {
public:
    bool isUgly(int m) 
    {
        if (m <= 0) return false;
        while(m > 1)
        {
            if (m % 2 == 0) m = m / 2;
            else if (m % 3 == 0) m = m / 3;
            else if (m % 5 == 0) m = m / 5;
            else break;
        }

        if(m==1) return true;
        else return false;
       
    }
};
