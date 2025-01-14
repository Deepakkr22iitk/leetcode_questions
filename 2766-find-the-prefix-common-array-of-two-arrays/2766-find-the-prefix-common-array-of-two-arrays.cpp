class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n=A.size();
        set<int> taken;
        for(int i=0;i<n;++i)
        {
            taken.insert(A[i]);
            int count=0;
            for(int j=0;j<=i;++j)
            {
                if(taken.find(B[j])!=taken.end()) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};