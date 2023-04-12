class Solution {
public:
    string simplifyPath(string path) {
        
     //This is general method to tokenization the string in c++:   
     vector<string> v;
     string str;
      for(int i=0;i<path.size();i++){
	     char ch = path.at(i);
	           if(ch!='/'){ 
                   str+=ch;
               }
	           else{
	             v.push_back(str);
	             str.clear();
               }
	  }
      v.push_back(str);   //always rember the last case is got rest:
      
      //logic:
	  stack<string> st;
      for(auto token : v){
           if(token=="" || token=="."){  //"." taken as string not compalsory as Character:
                continue;
            }
            else if(token!=".."){
                st.push(token);
            }
            else if(st.size()!=0){
                st.pop();
            }
      }

       if(st.empty()){
            return "/";
        }  

        string result="";
        while(!st.empty()){
            result = "/" + st.top() + result;  //reverse the order value store in the stack:
            st.pop();
        }
        return result;
        
    }
};
