/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int Binary_Search_left(int low,int high,int target,MountainArray &mountainArr){
            int result=-1;    //sorted in ascending order:
            while(low<=high){
                int mid = low+(high-low)/2;
                if(mountainArr.get(mid)==target){
                    result = mid;
                    return result;
                }
                else if(mountainArr.get(mid)<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            return result;
   }

   int Binary_Search_right(int low,int high,int target,MountainArray &mountainArr){
            //sorted in desceding order:
            int result = -1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(mountainArr.get(mid)==target){
                    result = mid;
                    return result;
                }
                else if(mountainArr.get(mid)<target){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return result;
   }




    int findInMountainArray(int target, MountainArray &mountainArr) {

         int low=0;
         int high = mountainArr.length()-1;
         while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int peak_element = low;

        cout<<peak_element<<endl;

         int val1=Binary_Search_left(0,peak_element,target,mountainArr);
         if(val1!=-1){
             return val1;
         }
      
       int n = mountainArr.length()-1;
       int val2 = Binary_Search_right(peak_element+1,n,target,mountainArr);
        if(val2!=-1){
            return val2;
        }
        return -1;
     
        
         
    }
};
