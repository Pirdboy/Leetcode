//Title:Reverse Nodes in k-Group
class Solution {
public:
    bool enough(ListNode* curr,int k){
        if(curr==NULL)
            return false;
        int count=0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        return count>=k?true:false;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k==0 || k==1)
            return head;
        ListNode* beHead=new ListNode(-1);
        ListNode* curr=beHead;
        curr->next=head;
        ListNode* newHead=NULL;
        bool ok=enough(curr,k);
        if(!ok){
            newHead=head;
        }
        else{
            while(ok){
                vector<ListNode*> nodes(k+2);
                for(int i=0;i<k+2;i++){
                    if(i>0)
                        nodes[i]=nodes[i-1]->next;
                    else
                        nodes[i]=curr;
                }
                for(int i=k;i>1;i--){
                    nodes[i]->next=nodes[i-1];
                }
                nodes[1]->next=nodes[k+1];
                nodes[0]->next=nodes[k];
                if(newHead==NULL){
                    newHead=nodes[k];
                }
                curr=nodes[1];
                ok=enough(curr,k);
            }
        }
        return newHead;
    }
};