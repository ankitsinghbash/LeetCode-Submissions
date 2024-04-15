class Solution {
public:
    string removeKdigits(string num, int k) {
           if(num.size()==k){
            return "0";
           }

           stack<char> st;
           //st.push(num[0]);
           for(int i=0;i<num.size();i++){
              while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;
              }
              st.push(num[i]);
           }


           while(k>0 && !st.empty()){
            st.pop();
            k--;
           }

           string temp;
           while(!st.empty()){
               temp.push_back(st.top());
               st.pop();
           }
           reverse(temp.begin(),temp.end());

           int m = temp.size();
           
          
           int i=0;
           while(temp[i]=='0'){
            i++;
           }

          string result = "";
           for(int k=i;k<temp.size();k++){
              result.push_back(temp[k]);
           }

            if (result.size() == 0)   //case of "10" k=1;
                result.push_back('0');
           return result;
    }
};

