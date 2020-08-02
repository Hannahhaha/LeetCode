#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x),next(NULL){}
};

class Solution{
  public:
     ListNode* MergeKLists(vector<ListNode*>& lists){
         ListNode* answer=NULL;
         for(int i=0;i<lists.size();++i)
         {
             answer=MergeTwoList(answer,lists[i]);
         }
         return answer;
     }

     ListNode* MergeTwoList(ListNode* l1,ListNode* l2){
         ListNode* head=new ListNode(-1);
         ListNode* cur=head;
         while(l1!=NULL&&l2!=NULL)
         {
             if(l1->val<l2->val)
             {
                 cur->next=l1;
                 l1=l1->next;
             }
             else
             {
                 cur->next=l2;
                 l2=l2->next;
             }
             cur=cur->next;             
         }
         cur->next=(l1==NULL?l2:l1);
         return head->next;
     }
};