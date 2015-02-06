//Title:Remove Nth Node From End of List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        if(n==count){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        curr=head;
        int pos=1;
        while(pos<count-n){
            curr=curr->next;
        }
        ListNode* temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        return head;
    }
};