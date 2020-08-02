#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
   public:
       ListNode* DeleteLNNode(ListNode* head,int n){
          ListNode* ans=new ListNode(0);
          ans->next=head;//head的next
          
          ListNode* fast=ans;
          ListNode* slow=ans;
          for(int i=0;i<n;++i)
          {
              fast=fast->next;
          } 

          while(fast->next!=NULL){
              fast=fast->next;
              slow=slow->next;
          }
          slow->next=slow->next->next;
          return ans->next;
       }
};