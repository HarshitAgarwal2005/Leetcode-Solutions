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
    
     ListNode* reverseList(ListNode* head) { // recursive soln
        if (head==NULL || head->next==NULL){
           return head;
        }
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* c= new ListNode(10);
        //deep copy of old linked list
        ListNode* temp=head;
        ListNode* tempC= c;
        while(temp){
            ListNode* node = new ListNode(temp->val);
            tempC->next=node;
            temp=temp->next;
            tempC=tempC->next;
        }
        c=c->next;
        c= reverseList(c);
        ListNode* a = head;
        ListNode* b= c;
        while(a){
            if(a->val!=b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;
    
    }
};