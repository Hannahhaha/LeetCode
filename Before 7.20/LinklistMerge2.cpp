#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
  public:
     ListNode* MergeTwoList(ListNode* l1,ListNode* l2)
     {
        ListNode* Head=new ListNode(-1);
        ListNode* cur=Head;

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
        cur->next=(l1=NULL?l2:l1);
        return Head->next;
     }


     ListNode* merge(vector<ListNode*>& lists,int l,int r){
         if(l==r)return lists[l];
         if(l>r)return NULL;
         int mid=(l+r)/2;
         return MergeTwoList(merge(lists,l,mid),merge(lists,mid+1,r));
     }

     ListNode* Merge(vector<ListNode*>& lists){
         return merge(lists, 0, lists.size()-1);
     }







};