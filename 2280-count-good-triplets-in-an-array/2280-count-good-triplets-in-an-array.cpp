class Solution {
public:
    class segTree{
        vector<int>tree;
        public:
        segTree(int n)
        {
            tree.resize(4*n+1);
        }
        void build(vector<int>&nums,int tl,int tr,int v=1)
        {
            if(tl>tr) return;
            if(tl==tr)
            {
                tree[v]=nums[tl];
                return;
            }
            int mid=(tl+tr)/2;
            build(nums,tl,mid,2*v);
            build(nums,mid+1,tr,2*v+1);
            tree[v]=tree[2*v]+tree[2*v+1];
        }
        void update(int idx,int val,int v,int tl,int tr)
        {
            if(tl>tr) return;
            if(idx<tl || idx>tr) return;

            if(tl==tr)
            {
                tree[v]=val;
                return;
            }

            int mid=(tl+tr)/2;
            update(idx,val,2*v,tl,mid);
            update(idx,val,2*v+1,mid+1,tr);
            tree[v]=tree[2*v]+tree[2*v+1];
        }

        int query(int v,int tl,int tr,int l,int r) 
        {      
            if (l>r) return 0;
            if (l == tl && r == tr) return tree[v];
        
            int tm=(tl+tr)/2;
            return query(v*2,tl,tm,l,min(r,tm)) + query(v*2+1,tm+1,tr,max(l,tm+1),r);
        }

    };
    // we can leverage the Segment Tree to count the number of common elements with the sum by updating the values with '1' for each of
    // index in the second vector
    // Here the sum is build on the index value and it's always increased by '1'. 

    // Let us consider these two arrays [1,4,2,0,6,5,3,7] [1,4,3,7,0,2,6,5]
    // Now the main observation of the question is-
    // Let's say if i am currently at 5th index in first array then we will find it's corresponding position in second array. In the above example it would be at second last position in second array.
    // Now for current index my answer would be (common elements in left part of first array and common elements in left part of second array) multiplied by (common elements in right part of first array and common elements in right part of second array).
    // In above case for 5th index [1,4,2,0] is common in left part and [5] is common in right part.

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        map<int,int>mp;
        for(int i=0;i<n;++i) mp[nums2[i]]=i;
        
        vector<int>nums(n);
        segTree st(n);
        st.build(nums,0,n-1);

        long long ans=0;
        st.update(mp[nums1[0]],1,1,0,n-1);
        
        // Now, we'll check for each of the 'i' considering i'th element as the middle element i.e., 'y'
        for(int i=1;i<n-1;++i)
        {
            int idx=mp[nums1[i]];
            long long common_on_left=st.query(1,0,n-1,0,idx);
            long long unique_on_left=i-common_on_left;
            long long common_on_right=n-1-idx-unique_on_left;

            ans+=common_on_left*common_on_right;
            st.update(idx,1,1,0,n-1);
        }
        return ans;
    }
};