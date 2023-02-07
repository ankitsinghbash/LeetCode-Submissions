class Solution {
public:
    int compress(vector<char>& chars) {
        //analysis the time-complexity: O(n) because iteration only one time from left->to->right:
        int n=chars.size();
        int i=0;
        int index=0;   //jisme value daalyga:
        while(i<n){
              char curr =  chars[i];
              int counter=0;
              while(i<n && chars[i] == curr){
                  counter++;
                  i++;
              }
               
             chars[index]=curr;
             index++;
             //chars me value put karo:
             if(counter>1){
                 string str=to_string(counter);
                 for(auto &ch : str){
                     chars[index]=ch;
                     index++;
                 }
             }

        }
        return index;
    }
};
