

class Solution {
public:
    
    int size(ListNode *head)
    {
        int counter=0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

       int L1 = size(headA);
       int L2 = size(headB); 
       int diff = abs(L1-L2);
       if(L1>L2)
       {
           //LL1 ko increase karo:
           for(int i=0;i<diff;i++)
           {
              ptr1=ptr1->next;
           }
       }
       else{
           //ll2 ko increase karo:
           for(int i=0;i<diff;i++)
           {
               ptr2=ptr2->next;
           }
       }

      while(ptr1!=NULL&&ptr2!=NULL)
      {
          if(ptr1==ptr2)
          {
              return ptr1;
          }

          ptr1=ptr1->next;
          ptr2=ptr2->next;
      }
      return NULL;
	}
  

   
};
