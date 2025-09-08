class Solution {
public:
    bool check(int m)
    {
        while(m)
        {
            if(m%10==0) return false;
            m/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i=1;
        while(i<n/2 && (!check(n-i) || !check(i)))
        {
            i++;
        }
        return {i,n-i};
    }
};