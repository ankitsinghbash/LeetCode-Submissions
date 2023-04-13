class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> lastoccur(26, 0);
        for(int i=0;i<s.length();i++)
            lastoccur[s[i]-'a'] = i; 

        vector<bool> visited(26,false);
        for(int i=0;i<s.size();++i){
              char ch = s.at(i);
                if(visited[ch-'a']==true){
                    continue;
                }
                 while(st.size()>0 && st.top()>ch && i<lastoccur[st.top()-'a'] && i<lastoccur[st.top()-'a']){  
                      visited[st.top()-'a']=false;
                      cout<<"out element"<<st.top()<<endl;
                      st.pop();
                     
                 }
                 
                     st.push(ch);
                     cout<<"push element"<<ch<<endl;
                     visited[ch-'a']=true;
                 
               
        }

        string ans="";
        while(!st.empty()){
           ans+=st.top();
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
