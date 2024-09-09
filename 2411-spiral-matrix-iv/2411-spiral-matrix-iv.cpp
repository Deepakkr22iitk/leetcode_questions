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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int si=0,ei=m-1;
        int sj=0,ej=n-1;

        while(head)
        {
            for(int j=sj;j<=ej;++j)
            {
                if(head) 
                {
                    ans[si][j]=head->val;
                    head=head->next;
                }
                else return ans;
            }

            si++;
            for(int i=si;i<=ei;++i)
            {
                if(head)
                {
                    ans[i][ej]=head->val;
                    head=head->next;
                }
                else return ans;
            }
            ej--;

            for(int j=ej;j>=sj;--j)
            {
                if(head)
                {
                    ans[ei][j]=head->val;
                    head=head->next;
                }
                else return ans;
            }
            ei--;
            for(int i=ei;i>=si;--i)
            {
                if(head)
                {
                    ans[i][sj]=head->val;
                    head=head->next;
                }
                else return ans;
            }
            sj++;
        }
        return ans;
    }
};