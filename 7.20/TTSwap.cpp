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
   
   ListNode* SwapPairs(ListNode* head)
   {
       ListNode* cur=new ListNode(-1);
       cur->next=head;
       ListNode* res=cur;

       while(cur->next&&cur->next->next)
       {
          ListNode* a=cur->next;
          ListNode* b=cur->next->next;
          
          cur->next=a->next;
          a->next=b->next;
          b->next=a;
          cur=a;

       }
       return res->next;


   }
   
   
   



};


/*
class TTSwap
{
public:
   ListNode* SwapPairs(ListNode* head)
   {
       if(head==nullptr)
           return NULL;
       if(head->next==nullptr)
           return head;
        
        swap(head,head->next);
        SwapPairs(head->next->next);
        return head;
   }

   ListNode* swap(ListNode* Node1,ListNode* Node2)
   {
       int temp=Node1->val;
       Node1->val=Node2->val;
       Node2->val=temp;
   }
}；
*/