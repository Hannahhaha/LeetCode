#include<iostream>
#define OK true
#define ERROR false
using namespace std;

struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x):val(x),next(NULL){}
};

class CircleLinkedlist
{
public:
    ListNode* Circle(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                return true;
            } 
        }
        return false;
    }
};
