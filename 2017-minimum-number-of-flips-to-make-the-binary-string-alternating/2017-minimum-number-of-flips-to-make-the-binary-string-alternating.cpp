class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < 2 * n; i++) {
            char expect1 = (i % 2 == 0) ? '0' : '1'; // 0101...
            char expect2 = (i % 2 == 0) ? '1' : '0'; // 1010...

            if (t[i] != expect1) diff1++;
            if (t[i] != expect2) diff2++;

            if (i >= n) {
                char oldExpect1 = ((i - n) % 2 == 0) ? '0' : '1';
                char oldExpect2 = ((i - n) % 2 == 0) ? '1' : '0';

                if (t[i - n] != oldExpect1) diff1--;
                if (t[i - n] != oldExpect2) diff2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};