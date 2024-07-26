class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
              //1.insertion sort:  //array[i+1] always greater then arr[i] else swap:
              //2.bubble sort:  swap adjcent node and put most greater to the end of the array:
              //3.selection sort: find the smallest array value and swap with 
              //4.merge sort:
              //5.quick sort:
        
        //Insertion Sorting:  pass 16
        //    int n = arr.size();
        //    for(int i=0;i<n;i++){
        //            int j = i-1;
        //            int temp = arr[i];
        //            while(j>=0  && arr[j]>temp){
        //                 arr[j+1] = arr[j];
        //                 j--;
        //            }

        //            arr[j+1] = temp;
        //    }
        //    return arr;



         //Bubble sorting: pass 12
        //  int n  = arr.size();
        //  for(int i=0;i<n-1;i++){
        //       bool flag=true;
        //        for(int j=0;j<n-i-1;j++){
        //             if(arr[j]>arr[j+1]){
        //                 swap(arr[j],arr[j+1]);
        //                 flag=false;
        //             }
        //        }

        //        if(flag==true){
        //         break;
        //        }
        //  }
        //  return arr;


        //Selection Sort: //pass 12
        // int n = arr.size();
        // for(int i=0;i<n;i++){
        //       int j = i;
        //       int mini = INT_MAX;
        //       int idx;
        //       while(j<n){
        //            if(arr[j]<mini){
        //                mini = arr[j];
        //                idx = j;
        //            }
        //            j++;
        //       }
        //       swap(arr[i],arr[idx]);
        // }
        // return arr;

  

        //merge sort:

        // int low = 0;
        // int high = arr.size()-1;
        // while(low<=high){
        //       int mid = low+(high-low)/2;
              
        // }

        sort(nums.begin(),nums.end());

        return nums;

















        //Quick sort:
          


    }
};
