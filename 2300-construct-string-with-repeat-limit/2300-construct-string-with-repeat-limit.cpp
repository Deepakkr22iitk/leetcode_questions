class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());

        string ans;
        int freq = 1;
        int pointer = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (!ans.empty() && ans.back() == s[i]) {
                if (freq < repeatLimit) {
                    ans += s[i];
                    freq++;
                } else {
                    pointer = max(pointer, i + 1);
                    while (pointer < s.size() && s[pointer] == s[i]) {
                        pointer++;
                    }

                    if (pointer < s.size()) {
                        ans += s[pointer];
                        swap(s[i], s[pointer]);
                        freq = 1;
                    } else {
                        break;
                    }
                }
            } else {
                ans += s[i];
                freq = 1;
            }
        }

        return ans;
    }
};