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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // //code 1
        // ListNode* tempA=a;
        // ListNode* tempB=b;
        // ListNode* c= new ListNode(-1);
        // ListNode* tempC=c;
        // while(tempA!=NULL && tempB!=NULL){
        //     if(tempA->val<=tempB->val){
        //         ListNode * t=new ListNode(tempA->val);
        //         tempC->next=t;
        //         tempC=t;
        //         tempA=tempA->next;  
        //     }
        //     else{
        //         ListNode * t=new ListNode(tempB->val);
        //         tempC->next=t;
        //         tempC=t;
        //         tempB=tempB->next;  
        //     }
        // }
        // if(tempA==NULL){
        //     tempC->next=tempB;

        // }
        // else{
        //     tempC->next=tempA;
        // }
        // return c->next;

        //code 2
        //O(1) space
        ListNode* c= new ListNode(-1);
        ListNode* temp=c;
        while(a!=NULL && b!=NULL){
           if(a->val<=b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;
           } 
           else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
           }
        }
         if(a==NULL){
            temp->next=b;

        }
        else{
            temp->next=a;
        }
        return c->next;
    }
};