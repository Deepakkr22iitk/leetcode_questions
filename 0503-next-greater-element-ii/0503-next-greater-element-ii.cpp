class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);

        stack<int> st;
        for(int i = 2*n - 1; i >= 0; i--){
            // we will pop until all less equal elements are out
            while(!st.empty() && (st.top() <= nums[i % n])) st.pop();

            // if stack is empty means no greater element
            // if not empty we make the top as the answer
            if((i < n) && !st.empty()){
                nge[i] = st.top();
            }
            st.push(nums[i % n]); 
        }
        return nge;
    }
};