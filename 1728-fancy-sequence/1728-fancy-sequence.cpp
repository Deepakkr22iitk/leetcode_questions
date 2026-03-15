typedef long long ll;

class Fancy {
public:
    const ll MOD = 1000000007;
    
    vector<ll> arr;
    ll mul = 1;
    ll add = 0;

    ll modpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    ll modinv(ll x) {
        return modpow(x, MOD - 2);
    }

    Fancy() {
        arr.clear();
    }
    
    void append(int val) {
        ll x = ((val - add) % MOD + MOD) % MOD;
        x = (x * modinv(mul)) % MOD;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        ll val = arr[idx];
        val = (val * mul) % MOD;
        val = (val + add) % MOD;
        return (int)val;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */