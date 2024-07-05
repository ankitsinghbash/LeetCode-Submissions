class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
          vector<int> ans(2,0);
          
  
          vector<int> box; //store critical points:
          ListNode *temp = head;
          ListNode *prev = NULL;
          int idx=1;
          while(temp!=NULL){
              if(temp==head){
                  prev = temp;
                  temp = temp->next;
                  idx++;
                  continue;
              }
              else if(temp->next == NULL){
                prev = temp;
                temp = temp->next;
                idx++;
                continue;
              }
              else{
                     ListNode *node_right = temp->next;
                     //critical point for minima:
                     if(prev->val>temp->val && node_right->val>temp->val){
                            box.push_back(idx);
                     }
                     else if(prev->val<temp->val && node_right->val<temp->val){
                            box.push_back(idx);  //this is for store the index of maxima critical point
                     }

              }
        
             prev = temp;
             temp = temp->next;
             idx++;

          }

          if(box.size()<2){
            return {-1,-1};
          }


          sort(box.begin(),box.end());
         
          int n = box.size();
          int maxx = box[n-1]-box[0];

          int mini  = INT_MAX;
          for(int i=1;i<box.size();i++){
             mini = min(mini,box[i]-box[i-1]);
          }


          ans[0] = mini;
          ans[1] = maxx;




          return ans;
    }
};
