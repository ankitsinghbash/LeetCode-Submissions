class Solution {
public:
    bool checkRecord(string s) {
     
     int countA=0;
     for(int i=0;i<s.size();i++){
         char ch = s.at(i);
         if(ch=='A'){
             countA++;
         }
     }
     if(2<=countA) return false;

     //count the maximum contiueous L;
          int cL=0;
     int maxx=INT_MIN;
     for(int i=1;i<s.size();i++){
          char ch1 = s.at(i);
          if(ch1=='L'){
             char ch = s.at(i-1);
             if(ch1==ch){
               cL++;
             }
             else{
               cL=0;
             }
             
          }
          maxx=max(maxx,cL);
     }
     maxx++;
     if(2<maxx){
         return false;
     }
     return true;

    }
};
