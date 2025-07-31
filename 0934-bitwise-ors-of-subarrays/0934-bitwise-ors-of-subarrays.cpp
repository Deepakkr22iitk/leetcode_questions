class Solution {
public:
    // Let's suppose the array as [1,3,4,6,5] or [001,011,100,110,101]
    // All the subarrays are:
    // [001]
    // [001 011] [011]
    // [001 011 100] [011 100] [100]
    // [001 011 100 110] [011 100 110] [100 110] [110]
    // [001 011 100 110 101] [011 100 110 101] [100 110 101] [110 101] [101]

    // Calculate the OR operations for each subarray 
    // 001
    // 011 011
    // 111 111 100
    // 111 111 110 110
    // 111 111 111 111 101

    // There are O(N^2) numbers in total, which is not acceptable.

    // After removing duplicate numbers in each line, it becomes:
    // 001
    // 011
    // 111 100
    // 111 110
    // 111 101

    // In each line t, for any two numbers t[i] and t[j] (i < j), t[i] must have more 1s than t[j]. So the length of each line will 
    // not exceed 32. So if we remove duplicate numbers, the complexity would not be very large
    // TC: O(32*N)
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>ans;
        set<int>prev;
        for(auto &x:arr)
        {
            set<int>curr;
            curr.insert(x);
            for(auto &y:prev) curr.insert(x|y);
            prev=curr;
            for(auto &y:prev) ans.insert(y);
        }
        return ans.size();
    }
};