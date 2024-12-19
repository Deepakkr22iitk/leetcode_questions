class Solution {
public:
    bool pred(vector<int> &weights,int cap,int days)
    {
        int req=0,sum=0,idx=0,n=weights.size();
        // why are we initiating req with 0?
        // why not with 1?
        // because in the end when idx==n there will be one last batch which should be 
        // counted and also if we do some handwork we will get this with ease

        // so instead of copying from others without understanding spend some time on code
        while(idx<n)
        {
            if(weights[idx]>cap) return false;
            while(idx<n && (sum+weights[idx])<=cap)
            {
                sum+=weights[idx];
                idx++;
            }
            req++;
            sum=0;
        }
        return req<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=accumulate(weights.begin(),weights.end(),0),ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(pred(weights,mid,days))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};