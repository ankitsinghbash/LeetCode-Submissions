class Solution {
public:
    bool detectCapitalUse(string word) {
        int counter=0;
        int smallerare=word.size()-1;
        int x=0;
        for(int i=0;i<word.size();i++)
        {
            char ch = word.at(i);
            if(isupper(ch)){
                counter++;
            }
            if(islower(ch)){
                x++;
            }
            
            if(isupper(word.at(0)) && x==word.size()-1)
            {
               return true;
            }
        }
      
        if(counter==word.size())
        {
           return true;
        }
        else if(counter==0){
            return true;
        }
        else{
            return false;
        }
    }
};
