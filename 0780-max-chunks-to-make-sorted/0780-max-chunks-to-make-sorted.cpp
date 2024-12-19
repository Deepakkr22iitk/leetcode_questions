class Solution {
public:
    // we are keeping tracking of all the elements passed till that point
    // since we want all of them to be in sorted, so when we found that biggest-smallest+1
    // is equal to the number of elements inside the set
    // we can partition that and 
    // then empty our set and update the next first=last+1
    int maxChunksToSorted(vector<int>& arr) {
        // int n=arr.size();
        // int ans=0;
        // set<int> st;
        // int first=0;
        // for(int i=0;i<n;++i)
        // {
        //     st.insert(arr[i]);
        //     int sz=st.size();
        //     auto it=st.end();
        //     it--;
        //     int last=*it;
        //     if(sz==(last-first+1)) 
        //     {
        //         ans++;
        //         first=last+1;
        //         st.clear();
        //     }
        // }
        // return ans;

        //sum1 is sum of 0.........i
        //co is sum of v[0],v[1].......v[i]
        int i,co=0,sum1=0,ans=0;
        for(i=0;i<arr.size();i++)
        {
            sum1+=i;
            co+=arr[i];
            if(sum1==co)
                ans++;
        }
        return ans;
    }
};