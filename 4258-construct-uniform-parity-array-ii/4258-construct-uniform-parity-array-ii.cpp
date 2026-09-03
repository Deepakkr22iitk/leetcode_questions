class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int oddCnt=0;
        int mnOdd=1e9+1;
        for(int i=0;i<n;++i)
        {
            if(nums1[i]%2==1) 
            {
                oddCnt++;
                mnOdd=min(mnOdd,nums1[i]);
            }
        }
        if(oddCnt==n || oddCnt==0) return true;

        int flag=1;
        // if we try for all odd
        for(int i=0;i<n;++i)
        {
            if(nums1[i]%2==1) continue;
            else if(mnOdd>nums1[i]) flag=0;
        }

        // we are not trying for all even
        // Because this is not possible, at this point, we are looking for an array 
        // consisting of both(odd & even) so in this [how will we change the mnOdd?]
        
        return flag==1;
    }
};