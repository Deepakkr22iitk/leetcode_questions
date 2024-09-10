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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        
        ListNode* prev=head;
        while(prev->next)
        {
           ListNode* curr=prev->next;
           int val1=prev->val;
            int val2=curr->val;
            int rem=__gcd(val1,val2);
            ListNode* bet=new ListNode(rem);
            prev->next=bet;
            bet->next=curr;
            prev=curr;
        }
        return head;
    }
};