class Solution {
public:
    bool rotateString(string s, string goal) {
        
        //let take main string;
        string whole_str = s+s;
        if(s.size()!=goal.size())
        {
            return false;
        }
        else
        {
            if(whole_str.find(goal)!=string::npos)  //string::npos=NULL;
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        
    }
};
