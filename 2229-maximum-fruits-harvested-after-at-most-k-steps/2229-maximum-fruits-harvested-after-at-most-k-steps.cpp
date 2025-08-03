class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = 2*1e5+1;

        vector<int> prefix(n); // it will stores the number of fruits till ith position

        for(auto it: fruits){
            prefix[it[0]] = it[1];
        }
        for(int i = 1 ;i< n;i++)
            prefix[i] += prefix[i-1];

        int maxi =0;

        // first go to right

        for(int i = startPos; i <= min(startPos+k , n-1);i++){
            int rightMost = i;
            int diff = i-startPos;
            int rem = (k-2*diff);
            int leftMost = startPos;
            if(rem>0) leftMost =  startPos - rem;  // ensuring that it is moving to the left side
            int sum = prefix[rightMost];
            if(leftMost > 0){
                sum -= prefix[leftMost-1];
            }
            maxi = max(maxi , sum);
        }

        //first go to left
        for(int i = startPos; i >= max(startPos-k , 0);i--){
            int leftMost = i;
            int diff = startPos-i;
            int rem = (k - 2*diff);
            // int rightMost = startPos + rem;
            // rightMost = min(n-1,rightMost);
            // rightMost = max(rightMost , startPos);
            int rightMost=startPos;
            if(rem>0) rightMost = min(n-1,startPos+rem); // ensuring that it doesn't cross n
            int sum = prefix[rightMost];
            if(leftMost > 0){
                sum -= prefix[leftMost-1];
            }
            maxi = max(maxi , sum);
        }

        return maxi;
    }
};