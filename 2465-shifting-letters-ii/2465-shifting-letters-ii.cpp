class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int l=s.size();
        vector<int>pre(l+5);
        for(int i=0;i<n;++i)
        {
            int l=shifts[i][0];
            int r=shifts[i][1];
            int dir=shifts[i][2];

            if(dir==0)
            {
                pre[l]--;
                pre[r+1]++;
            }
            else 
            {
                pre[l]++;
                pre[r+1]--;
            }
        }
        int val=0;
        for(int i=0;i<l;++i)
        {
            val+=pre[i];
            val%=26;                // It might be possible that this value becomes very large.
            int curr=s[i]-'a';

            s[i]=(char)(97+(curr+val+26)%26);
        }
        return s;
    }
};