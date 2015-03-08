//Title:Merge Two Sorted Lists
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* l3 = new ListNode(-1);
        ListNode* curr=l3;
        while(l1!=NULL && l2!=NULL){
            int v1=l1->val,v2=l2->val;
            if(v1<v2){
                curr->next=new ListNode(v1);
                curr=curr->next;
                l1=l1->next;
            }
            else if(v1>v2){
                curr->next=new ListNode(v2);
                curr=curr->next;
                l2=l2->next;
            }
            else if(v1==v2){
                curr->next=new ListNode(v1);
                curr=curr->next;
                curr->next=new ListNode(v2);
                curr=curr->next;
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(l1==NULL && l2==NULL){
            //do nothing
        }
        else if(l1!=NULL){
            while(l1!=NULL){
                int v=l1->val;
                curr->next=new ListNode(v);
                curr=curr->next;
                l1=l1->next;
            }
        }
        else if(l2!=NULL){
            while(l2!=NULL){
                int v=l2->val;
                curr->next=new ListNode(v);
                curr=curr->next;
                l2=l2->next;
            }
        }
        return l3->next;
    }
};
