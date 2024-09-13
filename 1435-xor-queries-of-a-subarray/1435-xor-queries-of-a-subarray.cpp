class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        int n=arr.size();
        for (int i=1;i<n;++i) arr[i] ^= arr[i - 1];

        for (auto &q: queries)
        {
            int val=arr[q[1]];
            if(q[0]>0)
            {
                val^=arr[q[0]-1];
            }
            res.push_back(val);
        }
        return res;
    }
};