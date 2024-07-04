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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* iterate=head->next;  // starting from the node after the intial 0.
        ListNode* nxtSum=iterate;

        while(nxtSum!=nullptr)
        {
            int sum=0;
            // finding the sum of all the nodes val between the two zeros.
            while(nxtSum->val!=0)
            {
                sum+=nxtSum->val;
                nxtSum=nxtSum->next;
            }

            // assigin the sum value to the current node's value.
            iterate->val=sum;
            // move nxtSum to the first non-zero value of the nxt block.
            nxtSum=nxtSum->next;
            // Move modify also to this node.
            iterate->next = nxtSum;
            iterate=iterate->next;

        }
        return head->next;
    }
};