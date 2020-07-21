
#include<iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res=NULL;
        ListNode* cur=head;
        ListNode* pre=NULL;

        while(cur!=NULL){
            ListNode* pNext=cur->next;
            if(pNext==NULL){
                res=cur;
            }
            cur->next=pre;
            pre=cur;
            cur=pNext;
        }
        return res;
    }
};