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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL){
            ++len;
            cur = cur->next;
        }

        vector<ListNode*> ans(k, NULL);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int rem = len % k;
        for(int i = 0 ; i < k ; i++){
            ans[i] = curr;
            for(int j = 0 ; j < len/k ; j++){
                prev = curr;
                curr = curr->next;
            }
            if(rem){
                prev = curr;
                curr = curr->next;
                rem--;
            }
            if(prev != NULL){
                head = curr;
                prev->next = NULL;
            }
        }
        return ans;
    }
};