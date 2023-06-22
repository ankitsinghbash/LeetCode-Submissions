class Solution {
public:
    vector<int> ans;
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry =0;
        int i=0;
        while(carry>=0 && i<digits.size()){
            int value;
            if(i==0){
              value = digits[i]+1+carry;
            }
            else{
             value = digits[i]+carry;
            }
            ans.push_back(value%10);
            carry = value/10;
            i++;
        }
        if(carry>0){
            ans.push_back(carry);
        }
        
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
