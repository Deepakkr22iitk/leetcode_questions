class FindSumPairs {
public:
    vector<int>val1;
    vector<int>val2;
    map<int,int>freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        val1.clear();
        val2.clear();
        val1=nums1;
        val2=nums2;
        for(auto &x:nums2) freq[x]++;
    }
    
    void add(int index, int val) {
        int prev=val2[index];
        int curr=prev+val;

        if(--freq[prev]==0) freq.erase(prev);
        freq[curr]++;
        val2[index]=curr;
    }
    
    int count(int tot) {
        int ans=0;
        int n=val1.size();
        for(int i=0;i<n;++i)
        {
            int req=tot-val1[i];

            if(freq.find(req)!=freq.end()) ans+=freq[req];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */