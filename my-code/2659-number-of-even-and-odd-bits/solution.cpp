class Solution {
public:
    
  long long DecimalToBinary(int n)
  {
    long long  binary=0;
    long long  i = 1;
    while (n != 0) {
        long long  rem = n % 2;
        binary = binary + rem * i;
        n=n/2;
        i*=10;
    }
    return binary;
  }
    
    
    vector<int> evenOddBit(int n) {
        string str = to_string(DecimalToBinary(n));
        reverse(str.begin(),str.end());
        vector<int> ans;
        int even=0;
        int odd=0;
        for(int i=0;i<str.size();++i){
            if(i%2==0 && str[i]=='1'){
                even++;
            }
            else if(i%2!=0 && str[i]=='1'){
                odd++;
            }
        }
        ans.push_back(even);
        ans.push_back(odd);
        return  ans;
    }
};
