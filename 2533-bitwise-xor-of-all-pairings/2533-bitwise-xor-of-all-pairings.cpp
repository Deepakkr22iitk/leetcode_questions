class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n%2==0 && m%2==0) return 0;
        
        int ans=0;
        if((n%2)==0)
        {
            ans=nums1[0];
            for(int i=1;i<n;++i) ans^=nums1[i];
            
            return ans;
        }
        
        if(m%2 ==0)
        {
            ans=nums2[0];
            for(int i=1;i<m;++i) ans^=nums2[i];
            
            return ans;
        }
        else
        {
            ans=nums1[0];
            for(int i=1;i<n;++i) ans^=nums1[i];
            
            for(int i=0;i<m;++i) ans^=nums2[i];
            
            return ans;
        }
    }
};