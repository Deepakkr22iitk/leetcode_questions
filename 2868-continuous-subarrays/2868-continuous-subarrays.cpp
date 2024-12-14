class Solution {
public:
    // Mine solution is quite nice.
    // The idea is same as to insert while maintaining the condition. This one-by-one erase of nums[i] would work here as even if 
    // in the next iteration nothing is getting pushed inside the set with the help of 'j' but we are adding the 'ans' from the 
    // previous valid set while incrementing 'i'.
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        multiset<int>st;
        int j=0;
        int i=0;
        while(i<n)
        {
            // This particular 'nums[j]' can be either greater than previous max element in set or it can be smaller than the 
            // previous min element in the set.
            while(j<n && (st.size()==0 || max(*(--st.end()),nums[j]) - min(*st.begin(),nums[j])<=2))
            {
                st.insert(nums[j]);
                j++;
            }

            ans+=st.size();
            st.erase(st.find(nums[i]));
            i++;
        }
        return ans;
    }
};