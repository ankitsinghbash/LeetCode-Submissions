class Solution {
public:
    long long coloredCells(int n) {
    long long sum=0;
    sum+=pow(n,2);
    sum+=pow(n-1,2);
    return sum;
 
    }
};
