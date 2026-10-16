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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow is at left middle
        ListNode* b=reverseList(slow->next);
        ListNode* a=head;
        slow->next=NULL; //for breaking the list
        //merge lists these a &b alternatively
        ListNode* c=new ListNode(100);
        ListNode* tempC=c;
        ListNode* tempA=a;
        ListNode* tempB=b;
        while(tempA!=NULL && tempB!=NULL){
            tempC->next=tempA;
            tempA=tempA->next;
            tempC=tempC->next;
            tempC->next=tempB;
            tempB=tempB->next;
            tempC=tempC->next;
        }
        tempC->next=tempA;
        head=c->next;
    }
};