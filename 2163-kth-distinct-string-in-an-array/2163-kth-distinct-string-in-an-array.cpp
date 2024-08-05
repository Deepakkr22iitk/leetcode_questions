class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>rk;
        int n=arr.size();
        for(int i=0;i<n;++i)
        {
            rk[arr[i]]++;
        }

        string ans="";
        for(int i=0;i<n;++i)
        {
            if(rk[arr[i]]==1) k--;

            if(k==0)
            {
                ans=arr[i];
                return ans;
            }
        }
        return ans;
    }
};