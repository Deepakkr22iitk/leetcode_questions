class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int l_ind=0,h_ind=0;
        int h_till=INT_MIN,l_till=INT_MAX;
        for(int i=0;i<n;++i)
        {
            if(h_till<nums[i])
            {
                h_ind=i;
                h_till=nums[i];
            }
            if(l_till>nums[i])
            {
                l_ind=i;
                l_till=nums[i];
            }
        }
        if(h_ind<l_ind) swap(h_ind,l_ind);
        // cout<<l_ind<<" "<<h_ind<<endl;
        return min((n-h_ind)+l_ind+1,min((h_ind+1),(n-l_ind)));
    }
};