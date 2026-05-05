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
    ListNode* findkthNode(ListNode* temp, int k){
        int ind = 1;
        while(temp != NULL && ind < k){
            temp = temp -> next;
            ind++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head -> next == NULL) return head;

        ListNode* tail = head;
        int len = 1;
        while(tail -> next != NULL){
            len++;
            tail = tail -> next;
        }
        if(k % len == 0) return head;
        k = k % len;
        tail -> next = head;
        ListNode* newLastNode = findkthNode(head, len - k);
        head = newLastNode -> next;
        newLastNode -> next = NULL;
        return head;
    }
};