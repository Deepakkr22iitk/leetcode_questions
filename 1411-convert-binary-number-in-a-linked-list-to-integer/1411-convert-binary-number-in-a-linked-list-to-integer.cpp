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
    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;

        ListNode* nnode=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return nnode;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp=reverse(head);
        int ans=0;
        int i=0;
        while(temp)
        {
            if(temp->val==1) ans|=(1<<i);
            i++;
            temp=temp->next;
        }
        return ans;
    }
};