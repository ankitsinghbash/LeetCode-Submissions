class Solution {
public:
  
  //111 --> 4 2 1 ==7;  //O(N):
   int decimal_to_string(string &s){
        int result = 0;
        int x =0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                   result = result + 1*pow(2,x);
            }
          x++;
        }
        return result;
   }


   vector<string> solve(int n){
       if(n==1){
           vector<string> vec;
           vec.push_back("0");
           vec.push_back("1");
           return vec;
       }
      
       vector<string> res = solve(n-1);
       vector<string> actual;
       for(int i=0;i<res.size();i++){
           string str = "0"+res[i];
           actual.push_back(str);
       }

       for(int i=res.size()-1;i>=0;i--){
           string str = "1"+res[i];
           actual.push_back(str);
       }

       return actual;


   }


    vector<int> grayCode(int n) {
        vector<int> ans;

        vector<string> store = solve(n);
        for(int i=0;i<store.size();i++){
            string str_val = store[i];
            int val = decimal_to_string(str_val);
            ans.push_back(val);
        }
        return ans;
    }
};
