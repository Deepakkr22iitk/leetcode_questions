class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int e_val=skill[n-1]+skill[0];
        long long ans=1LL*skill[n-1]*skill[0];
        int i=1,j=n-2;
        while(i<j)
        {
            int curr=skill[i]+skill[j];
            if(curr!=e_val) return -1;

            ans+=(1LL*skill[i])*(1LL*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};