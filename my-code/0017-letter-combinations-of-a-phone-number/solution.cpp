class Solution {
public:
    vector<string> lists = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    void help(int k,string path,string digits)
    {
       //here k is take value 2 for example "23"->digits;
       if(path.size()==digits.size())  //llike 23 size -> 2 and path size required also be 2 ex ad,ae,af,bd,be,bf,cd,ce,cf:
       {
           ans.push_back(path);
           return;
       }


       int idx=digits[k]-'0';  //give the index 2 after convert char to int:
       //required for idx 2 ka abc ke lyia:
       for(int i=0;i<lists[idx].size();++i)
       {
           path.push_back(lists[idx][i]);
           help(k+1,path,digits);
           path.pop_back();
       }


    }

    
    vector<string> letterCombinations(string digits) {
       if(digits.size()==0)
       {
           return ans; //empty;
       }
       int k=0;
       string path="";
       help(k,path,digits);
       return ans;
    }
};
