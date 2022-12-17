class Solution {
public:
         stack<long long> st; 
        int evalRPN(vector<string>& tokens) {
    	
        string first = tokens[0];
        int val = stoi(first);
        st.push(val);

    	for (long long i = 1; i < tokens.size(); i++) {
            string str = tokens[i];
    		if (str != "+" && str != "-" && str != "*" && str != "/"){
                int val  = stoi(str);
    			st.push(val);    //atoi(tokens[i].c_str()) also use to convert string to integer:
            }
    		else {
    			long long operand2 = st.top();
    			st.pop();
    			long long operand1 = st.top();
    			st.pop();
    			if (str == "+"){
    				long ans = operand1 + operand2;
                    st.push(ans);
                }
    			else if (str == "-"){
    				 long long  ans = operand1 - operand2;
                     st.push(ans);
                }
    			else if (str == "*"){
    				long long  ans = operand1 * operand2;
                    st.push(ans);
                }
    			else{
                    long long ans = operand1 / operand2;
                    st.push(ans);
                }
    				
    		} 
    	} 
    	return st.top();
     }
};



