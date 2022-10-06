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

    int sizeofLL(ListNode *head)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

     //two option:
     //count the size of the LinkedList then subtract the value of n from the size and then remove that element form start:
      int counter=0;
      int size=sizeofLL(head);
      int val=size-n;
      //remove the val element form start:
      if(n==0)
      {
          return head;
      }
      if(n==size)
      {
          head=head->next;
          return head;
      }

      if(val==0)
      {
          head=NULL;
          return head;
      }

      ListNode *temp=head;
      ListNode *prev=NULL;
      while(val!=0)
      {
          prev=temp;
          temp=temp->next;
          val--;
      }
      prev->next=temp->next;
      return head;
    }
};
