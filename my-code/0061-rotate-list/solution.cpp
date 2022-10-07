/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

   int size(ListNode *head)
   {
       int counter=0;
       ListNode *temp=head;
       while(temp!=NULL)
       {
           temp=temp->next;
           counter++;
       }
       return counter;
   }

   ListNode *solveans(ListNode *head,int time)
   {

        ListNode *temp=head;
        ListNode *prev=head;
       
        for(int i=1;i<=time;i++)
        {
            temp=temp->next;
        }
        //Now increament both:
         //requied the value ex= 1,2,3,4,5, and k=2; so required to go at 3:
        ListNode *prevofprev=NULL;
        ListNode *last=NULL;
        while(temp!=NULL)
        {
            prevofprev=prev;
            last=temp;
            prev=prev->next;
            temp=temp->next;
        }
        //here temp is NULL prev is the last element:
        //prevofprev is 3;
        prevofprev->next=NULL;
        last->next=head;
        head=prev;
        return head;
   }
    
    ListNode *rotateNow(ListNode *head,int k)
    {
        int totalsize=size(head);
        if(k==0||k<0||totalsize==k||totalsize==0||totalsize==1) return head;
        
        //base case when size is 1 ex [1] and k=4;
       
        
        if(k>totalsize)
        {
             int time=k%totalsize;
             //as we write the condition of k=0 in above write here also;
             if(time==0)
             {
                 return head;
             }
             return solveans(head,time);
        }

       if(k<totalsize)
       {
          return solveans(head,k);
       }
       return head;
    }
  
    ListNode* rotateRight(ListNode* head, int k) {
      
        return rotateNow(head,k);
    }
};

/*
//This is ok TLE due to one node rotate each at time:
class Solution {
public:
   
    int sizeofLL(ListNode *head)
    {
        ListNode *temp = head;
        int counter=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            counter++;
        }
        return counter;
    }

    ListNode *rotateNow(ListNode *head,int time)
    {
        while(time!=0)
        {
            //go to second last node:
            //and temp is the last node:
            //You now size so second last is size-1 or last is size;
            ListNode *temp=head;
            ListNode *prev=NULL;
            while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            //temp is last;
            //prev is second last;
            prev->next=NULL;
            temp->next=head;
            head=temp;
        }
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
     //three condition:
     int size=sizeofLL(head);
     if(k==size||k==0)
     {
         return head;  //no change return same list:
     }
     
     if(k>size)
     {
         int val=k%size;   //rotate val times:
         return rotateNow(head,val);
     }
    
    if(k<size)
    {
        return rotateNow(head,k);
    }

      return head;
    }
};


*/
