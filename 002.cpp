/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Title:Add Two Numbers
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int p=0;
        while(!(l1==NULL &&l2==NULL)){
            int a1=-1,a2=-1;
            if(l1!=NULL){
                a1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                a2=l2->val;
                l2=l2->next;
            }
            int c=-1;
            if(a1>=0 && a2>=0){
                c=a1+a2+p;
                if(c>=10){
                    p=1;
                }
                else 
                    p=0;
                c=c%10;
            }
            else if(a1<0 && a2>=0){
                c=a2+p;
                if(c>=10){
                    p=1;
                }
                else 
                    p=0;
                c=c%10;
            }
            else if(a1>=0 && a2<0){
                c=a1+p;
                if(c>=10){
                    p=1;
                }
                else 
                    p=0;
                c=c%10;
            }
            if(c>=0){
                curr->next = new ListNode(c);
                curr = curr->next;
            }
        }
        if(p==1)
            curr->next = new ListNode(p);
        return head->next;
    }
};
