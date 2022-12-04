class Solution {
public:
    int calPoints(vector<string>& str) {
        
        vector<int> ans;
        for(int i=0;i<str.size();i++)
        {
            
             string ch = str[i];
             if(ch=="C")
             {
                     ans.pop_back();
             }
             else if(ch=="D")
             {
                   int val = ans[ans.size()-1];
                   int total = val*2;
                   ans.push_back(total);
               
             }
             else if(ch=="+")
             {
                   int val1 = ans[ans.size()-1];
                   int val2 = ans[ans.size()-2];
                   int total = val1+val2;
                   ans.push_back(total);
             
             }
             else
             {
                  int chint = stoi(ch);
                  ans.push_back(chint);
             }
        }


        int total=0;
        for(int i=0;i<ans.size();i++)
        {
            total+=ans[i];
        }
        return total;

    }
};
