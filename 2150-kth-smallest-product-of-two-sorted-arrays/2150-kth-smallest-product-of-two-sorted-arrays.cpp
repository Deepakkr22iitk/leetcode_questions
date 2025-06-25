class Solution {
public:
    int findmaxIndex(vector<int>&nums2 , long long  val , long long midval)  // Upto this particular index, the multiplication with 'val' 
    {                                                                       // would be <=midval as 'val' >0
        int m=nums2.size();
        int l = 0,r=m-1,res=-1;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(val*nums2[mid]<=midval)
            {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res+1;
    }

    int findminIndex(vector<int>&nums2 , long long val , long long midval)// Since, 'val' here is < 0 so, post this particular index, the
    {                                               // multiplication would be <=midval as there will be multiplication of -ve with +ve
        int m=nums2.size();
        int l=0,r=m-1,res=m;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(val*nums2[mid]<=midval)
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return m-res;
    }
    
    bool check(long long midval,vector<int>& nums1, vector<int>& nums2, long long k){
        long long cnt=0;
        for(int i=0;i<nums1.size();++i)
        {
            long long val=nums1[i];
			if(val==0 and midval>=0) cnt+=nums2.size();
            
            else if(val>0) cnt+=findmaxIndex(nums2,val,midval);
            
            else if(val<0) cnt+=findminIndex(nums2,val,midval);
        }
        return cnt>=k;
    }
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l=-1e10,h=1e10;
        long long ans=-1;
        while(l<=h)
        {
            long long mid=(l+h)/2;
            if(check(mid,nums1,nums2,k)) 
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};