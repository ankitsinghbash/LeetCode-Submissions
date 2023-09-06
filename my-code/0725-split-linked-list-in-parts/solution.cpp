class Solution {
public:
   vector<ListNode*> ans;
   int counter(ListNode *&head){
     int cnt=0;
     ListNode *temp = head;
     while(temp!=NULL){
         temp = temp->next;
         cnt++;
     }
     return cnt;
   }



    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int delta = counter(head)%k;
        int timepart = counter(head)/k;
        ListNode *temp = head;
        for(int i=1;i<=k;i++){
            ListNode *latest = temp;
            if(delta>0){
                  ListNode *start = latest;
                  ListNode *prev = latest;
                  for(int i=1;i<=timepart+1;i++){
                      prev=latest;
                      latest=latest->next;
                  }
                  prev->next=NULL;
                  ans.push_back(start);

            } 
            else{
                ListNode *start=latest;
                ListNode *prev=latest;
                for(int i=1;i<=timepart;i++){
                        prev = latest;
                        latest=latest->next;
                }
                if(prev!=NULL){
                prev->next=NULL;
               }  
                ans.push_back(start);
            }
            temp = latest;
            delta--;
        }
        return ans;
    }
};
