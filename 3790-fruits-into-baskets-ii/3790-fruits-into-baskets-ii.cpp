class Solution {
public:
    // for each fruits[i] we are actually travelling the whole baskets and getting the leftmost
    // which is neither used till now and also not of less size than required

    // once it is used, we are marking it with the help of it's index
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        set<int> used;
        int f=0;
        int ans=0;
        while(f<n)
        {
            int b=0;
            while(b<n && (used.find(b)!=used.end() || baskets[b]<fruits[f])) b++;
            if(b!=n) used.insert(b);
            else ans++;
            f++;
        }
        return ans;
    }
};