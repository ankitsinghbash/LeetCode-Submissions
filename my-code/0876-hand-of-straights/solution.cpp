class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        //now iterate in map:
        

        auto it = mp.begin();
         while(it!=mp.end()){
               if(it->second>0){
                    for(int i=0;i<groupSize;i++){
                        if(mp[it->first+i]>0){
                              mp[it->first+i]--;
                        }
                        else{
                            return false;
                        }
                    }
               }
               else{
                it++;
               }
         }  
         return true;


    }
};
