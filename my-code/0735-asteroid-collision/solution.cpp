class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,char>> st;
        for(int i=0;i<asteroids.size();i++){
            int value = asteroids[i];
            char ch ;
            if(value>=0){
                ch = '+';
            }else{
                ch = '-';
            }
            pair<int,char> P  = {value,ch};
            bool ok = false;
            while(st.size()!=0 && st.top().second=='+' && P.second=='-'){
                    pair<int,char> p = st.top();
                    st.pop();
                    int value1 = P.first;
                    int value2 = p.first;
                    if(abs(value1)>abs(value2)){
                        int netvalue  = value1;
                        char sign = P.second;
                        P = {netvalue,sign};
                    }
                    else if(abs(value1)==abs(value2)){
                        ok = true;
                        break;
                    }
                    else{
                        int netvalue = value2;
                        char sign = p.second;
                        P = {netvalue,sign};
                    }
            }
            if(ok==false){
            st.push(P);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            pair<int,char>  pair= st.top();
            st.pop();
            int value = pair.first;
            ans.push_back(value);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
