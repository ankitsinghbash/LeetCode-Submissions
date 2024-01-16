class RandomizedSet {
public:
     vector<int> vec;
    RandomizedSet() {
        
    }

    bool ispresent(int target){
        int low=0;
        int high=vec.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(vec[mid]==target){
                return true;
            }
            if(vec[mid]<target){
                    low = mid+1;
            }
            else{
                 high = mid-1;
            }
        }
        return false;
    }
    
    bool insert(int val) {
        //check present or not:
        //if not present then insert it and return true 
        //else only return false;


        if(ispresent(val)){
            return false;
        }

        if(vec.size()==0){
            vec.insert(vec.begin(),val);
            return true;
        }

        if(val<vec[0]){
          vec.insert(vec.begin(),val);
          return true;
        }


        int low=0;
        int high =vec.size()-1;
        if(val>vec[high]){
              vec.insert(vec.end(),val);
              return true;
        }
        int result=0;
        while(low<high){
            int mid = (low+high)/2;
            if(vec[mid]<val){   //dont use present case here:
                low = mid+1;
                result = low;
            }
            else{
                high = mid;
            }
        }
        int idx = result;
        vec.insert(vec.begin()+idx,val);
        return true;
    }
    
    bool remove(int val) {
            //not present return false;
            //if present remove it:
            if(ispresent(val)==true){
                int low=0;
                int high=vec.size()-1;
                while(low<=high){
                    int mid = (low+high)/2;
                    if(vec[mid]==val){
                       vec.erase(vec.begin()+mid);   //delete my mid element:
                       return true;
                 }
                    if(vec[mid]<val){
                        low = mid+1;
                 }
                else{
                    high = mid-1;
               }
              }
            }
            return false;
    }
    
    int getRandom() {
         if(vec.size()==0)
         {
             return -1;
         }
         int idx = rand()%vec.size();
         int val = vec[idx];
         return val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
