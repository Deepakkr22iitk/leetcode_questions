class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans=prices;

        // solution 1    TC->O(n^2)
        // for(int i=0;i<n;++i)
        // {
        //     int j=i+1;
        //     while(j<n && prices[j]>prices[i]) j++;
        //     if(j<n) ans[i]=(prices[i]-prices[j]);
        //     else ans[i]=prices[i];
        // }
        // return ans;

        // solution 2    TC->O(n)
        stack<int> st;
        vector<int> greater_ele(n,n);// we will store index j on index i 
                                    // s.t prices[j]<=prices[i] & j>i
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty() && prices[st.top()]>prices[i]) st.pop(); // it can't be ans for any left 

            if(!st.empty()) greater_ele[i]=st.top(); // it can be a possible ans for left 

            st.push(i); // keeping it for the next left index
        } 

        for(int i=0;i<n;++i)
        {
            if(greater_ele[i]!=n) // checking whether we have found any index or not
            {
                ans[i]=prices[i]-prices[greater_ele[i]]; // if yes then we change it 
            }
            // else ans[i]=prices[i]; // if not then simply copy the price
        }

        return ans;
    }
};