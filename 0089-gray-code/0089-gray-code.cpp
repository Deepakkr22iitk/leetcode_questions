class Solution {
public:
    // kindly check how it's working
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++) 
            ans[i] = i^(i>>1);
        return ans;
    }

    // n=3
    
    // bit '1' used            no. of numbers              numbers
    //    0                         1                         0
    //    1                         2                       1,2,4
    //    2                         3                       3,5,6
    //    3                         1                         7

    //    possible ans =  0,1,3,2,6,7,5,4
};