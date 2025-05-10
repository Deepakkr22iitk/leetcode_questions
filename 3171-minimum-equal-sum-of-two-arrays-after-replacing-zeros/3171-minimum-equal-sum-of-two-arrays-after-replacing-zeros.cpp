class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        long long ans1=0,ans2=0;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;++i)
        {
            ans1+=(1LL*nums1[i]);
            if(nums1[i]==0) 
            {
                ans1+=1LL;
                cnt1++;
            }
        }
        for(int i=0;i<m;++i)
        {
            ans2+=(1LL*nums2[i]);
            if(nums2[i]==0) 
            {
                ans2+=1LL;   
                cnt2++;
            }
        }
        if(cnt1==0 && (ans1<ans2)) return -1;
        if(cnt2==0 && (ans1>ans2)) return -1;
        return max(ans1,ans2);
    }
};