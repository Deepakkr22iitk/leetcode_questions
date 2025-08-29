class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_even=1ll*n/2, n_odd=1ll*(n-n/2);
        long long m_even=1ll*m/2, m_odd=1ll*(m-m/2);

        long long ans=n_odd*m_even;
        ans+=n_even*m_odd;
        return ans;
    }
};