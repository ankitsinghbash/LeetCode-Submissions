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
 /*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode dummy(-1);
      ListNode *temp = &dummy;
      while(list1 != NULL && list2 != NULL){
       if(list1->val <= list2->val){
           temp->next = list1;   
          list1 = list1->next;
        } 
        else{
           temp->next = list2;
           list2 = list2->next;
         }
        temp = temp->next;
       }
   if(list1 == NULL){
     temp->next = list2;
    }
    else{
       temp->next = list1;
     }
     return dummy.next;   //not use dummy->next because dummy is not a pointer:
                           //dummy is the Listnode of dummy name assign with value _1 intitially:
    }
};
*/



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     //recursive approach of mergetwosorted LinkedList;
     if(list1==NULL)   //that base then list1 khatam ho gyi thi
     {
         return list2;
     }
     if(list2==NULL)    //that base when list2 khatam ho gyi thi
     {
         return list1;
     }

     if(list1->val<list2->val)
     {
          list1->next=mergeTwoLists(list1->next,list2);
          return list1;
     }
     else
     {
          list2->next=mergeTwoLists(list1,list2->next);
          return list2;
     }


    }
};
