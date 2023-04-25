class Solution {
public:
    //order of piece matter:
    //"L" left swifting of start only when "L" of target is toward left in target:
    //"R" right swifting of start only when "R" of target is toward right in target:
    bool canChange(string start, string target) {
        stack<pair<char,int>> st1;
        stack<pair<char,int>> st2;
        for(int i=0;i<start.size();i++){
            char ch = start.at(i);
            if(ch=='L' || ch=='R'){
                st1.push({ch,i});
            }
        }

        for(int i=0;i<target.size();i++){
            char ch = target.at(i);
            if(ch=='L' || ch=='R'){
                st2.push({ch,i});
            }
        }

        if(st1.size()!=st2.size()) return false;

        while(!st1.empty() || !st2.empty()){
            auto one = st1.top();
            auto two = st2.top();

            st1.pop();
            st2.pop();

            if(one.first!=two.first) return false;  //check order same hai ki nahi:

            if(one.first=='L'){
                 if(one.second<two.second){
                     return false;
                 }
            }
            if(one.first=='R'){
                 if(one.second>two.second){
                     return false;
                 }
            }
        }
        return true;

    }
};
