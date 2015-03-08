//Title:Swap Nodes in Pairs
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* beHead=new ListNode(-1);
        ListNode* curr=beHead;
        curr->next=head;
        ListNode* newHead=NULL;
        if(curr->next==NULL)
            return NULL;
        if(curr->next->next==NULL)
            newHead=curr->next;
        else 
            newHead=curr->next->next;
        while(curr!=NULL && curr->next!=NULL && curr->next->next!=NULL){
            ListNode* one=curr;
            ListNode* two=curr->next;
            ListNode* three=curr->next->next;
            ListNode* four=curr->next->next->next;
            one->next=three;
            three->next=two;
            two->next=four;
            curr=two;
        }
        return newHead;
    }
};
