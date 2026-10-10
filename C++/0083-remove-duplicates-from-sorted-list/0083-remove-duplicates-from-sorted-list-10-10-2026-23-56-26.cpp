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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* temp= head;
        // while(temp!= NULL){
        //     while(temp->next!= NULL && temp->next->val==temp->val){
        //         temp->next= temp->next->next;
        //     }
        //     temp= temp->next;
        // }
        // return head;
        if(head==NULL || head->next==NULL) return head;
        ListNode * a= head;
        ListNode* b= head->next;
        
        while(b!=NULL){
            while (b!=NULL && b->val==a->val){
                b=b->next;
            }
            a->next=b;
            a=b;
            if(b!=NULL) b=b->next;
        }
        return head;
    }
};