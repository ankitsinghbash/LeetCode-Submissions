class Solution {
public:
   
   int to_decimal(string &s)
{
    int ans  = 0;
    int power = s.size()-1;
    for(int i=0;i<s.size();i++){
           if(s[i]=='1'){
               ans+=pow(2,power);
           }
           power--;
    }
    return ans;
}


    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
             string str = nums[i];
             int val = to_decimal(str);
             st.insert(val);
        }

       int n = nums.size();
       int time = pow(2,n)-1;
       for(int i=0;i<=time;i++){
           if(st.find(i)==st.end()){
               bitset<16> b = bitset<16>(i);
               string stt = b.to_string();
               string ans = stt.substr(16-n,n);
               return ans;
           }
       }
       return "";


    }
};
