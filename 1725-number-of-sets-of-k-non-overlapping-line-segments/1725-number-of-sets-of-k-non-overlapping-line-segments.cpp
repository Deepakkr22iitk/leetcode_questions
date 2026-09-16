class Solution {
public:

    const int MOD = 1e9 + 7;

    // Fast exponentiation: calculates a^b % MOD
    int modPow(int a, int b){
        long long res = 1;

        while(b > 0){
            if(b & 1)
                res = (res * a) % MOD;

            a = 1LL * a * a % MOD;
            b >>= 1;
        }

        return (int)res;
    }

    int numberOfSets(int n, int k) {

        // We need C(n + k - 1, 2k)
        int a = n + k - 1;
        int b = 2 * k;

        int temp = b;

        long long res1 = 1; // Numerator
        long long res2 = 1; // Denominator

        // Build:
        // Numerator   = a * (a-1) * ... * (a-b+1)
        // Denominator = b!
        for(int i = 1; i <= temp; i++){

            res1 = 1LL * res1 * a % MOD;
            a--;

            res2 = 1LL * res2 * b % MOD;
            b--;
        }

        // Modular division:
        // res1 / res2
        // = res1 * inverse(res2)
        // --> inverse(res2) = res2^(MOD-2) % MOD

        int res = 1LL * res1 * modPow(res2, MOD - 2) % MOD;

        return (int)res;
    }
};