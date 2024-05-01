class Solution {
public:
    int minOperations(vector<string>& logs) {
        //stack problem:
        //x1/ push in stack , './' skip and '../' pop:
        //if more poping stack is empty do nothing.
        //return size of stack:
        //no multi-branching of folder is happen:


  
           stack<string> st;
           
           for(int i=0;i<logs.size();i++){
              string str = logs[i];
              if(str=="./"){
                continue;
              }
              else if(str!="../" && str!="./"){
                  st.push(str);
              }
              if(str=="../"){
                   if(st.empty()){
                        continue;
                   }
                   else{
                       st.pop();
                   }
              }

           }

          return st.size();

    }
};
