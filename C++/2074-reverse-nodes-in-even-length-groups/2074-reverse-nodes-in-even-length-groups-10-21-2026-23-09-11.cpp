/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newNode=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newNode;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(left==right) return head;
       ListNode* a =NULL;
       ListNode* b= NULL;
       ListNode* c= NULL;
       ListNode* d= NULL;
       ListNode* temp=head;
       int n=1;
       while(temp!=NULL){
        if(n==left-1) a=temp;
        if(n==left) b=temp;
        if(n==right) c=temp;
        if(n==right+1) d=temp;
        temp=temp->next;
        n++;
       }
       if(a!=NULL) a->next=NULL;  // if condition nhi lagao ge toh error aaye ga, do try dry run, vvimp to understand
       if(c) c->next=NULL;
       c=reverseList(b);
       if(a!=NULL) a->next=c;
       b->next=d;
       if(a!=NULL) return head;
       return c;
       

    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode*temp=head;
        int gap=1;
        while(temp!=NULL && temp->next!=NULL){
            int remLen=0;
            ListNode* t=temp->next;
            for(int i=0;i<=gap+1 && t!=NULL;i++ ){
                t=t->next;
                remLen++;
            }
            if(remLen<gap+1) gap=remLen-1;
            if(gap%2!=0) reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++){
                temp=temp->next;
            }
        }
        return head;
    }
};