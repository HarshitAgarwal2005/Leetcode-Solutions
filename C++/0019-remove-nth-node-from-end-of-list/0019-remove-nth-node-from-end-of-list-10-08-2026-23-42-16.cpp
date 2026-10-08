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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast = head;
        for(int i=1; i<=n+1;i++){
            if(fast==NULL){
                head=head->next;
                return head;
            }
            fast=fast->next;
        }
        while (fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;

        // int len=0;
        // ListNode* temp= head;
        // while (temp!=NULL){
        //     len++;
        //     temp=temp->next;
        // }
        // if (n==len){
        //     head=head->next;
        //     return head;
        // }
        // int m=len-n+1;
        // int idx=m-1;
        // temp=head;
        // for(int i=1;i<idx;i++){
        //     temp=temp->next;
        // }
        // temp->next=temp->next->next;
        // return head;
    }
};