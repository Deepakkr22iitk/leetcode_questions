class Solution {
public:
    // The idea is [0,...,ind1] and [ind2,...,n] of arr is sorted. 
    // Now Traversing in reverse order in ind1 till '0' to get the corresponding increasing part in second part i.e., from 
    // [ind2,...,n]
    // Similarly traverse in increasing order
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int ind1=0,ind2=n-1;
        int j=1;
        while(j<n && arr[j]>=arr[j-1])
        {
            ind1=j;
            j++;
        }
        j=n-2;
        while(j>=0 && arr[j]<=arr[j+1])
        {
            ind2=j;
            j--;
        }
        if(ind1==n-1) return 0;  // Reached one of the end, so simply return 0
        int ans=n-1;
        int temp1=ind1;
        while(ind1>=0)
        {
            int len=arr.end()-lower_bound(arr.begin()+ind2,arr.end(),arr[ind1]); //required len in increasing part of second part 
            int temp=ind1+1+len;  // total number of increasing elements under consideration
            ans=min(ans,n-temp);
            ind1--;
        }
        while(ind2<n)
        {
            int len=upper_bound(arr.begin(),arr.begin()+temp1,arr[ind2])-arr.begin();//required len in increasing part of first part 
            int temp=(n-ind2)+len;
            ans=min(ans,n-temp);
            ind2++;
        }
        return ans;
    }
};