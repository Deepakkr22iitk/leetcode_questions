class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[mid-1])
            {
                ans=mid;
                s=mid+1;
            }
            else e=mid;
        }
        return ans;
    }
};