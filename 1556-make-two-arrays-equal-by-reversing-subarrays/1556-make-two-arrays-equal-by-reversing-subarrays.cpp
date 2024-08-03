class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        map<int,int>rk;
        for(int i=0;i<n;++i)
        {
            rk[target[i]]++;
        }
        int m=arr.size();
        if(m!=n) return false;

        for(int i=0;i<m;++i)
        {
            if(rk.find(arr[i])==rk.end()) return false;
            rk[arr[i]]--;
            if(rk[arr[i]]==0) rk.erase(arr[i]);
        }

        return (rk.size()==0);
    }
};