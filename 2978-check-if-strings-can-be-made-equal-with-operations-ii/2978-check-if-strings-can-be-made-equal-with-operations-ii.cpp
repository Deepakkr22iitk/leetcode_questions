class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> odd(26, 0);
        vector<int> even(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for (int ele : odd) {
            if (ele != 0) return false;
        }

        for (int ele : even) {
            if (ele != 0) return false;
        }

        return true;
    }
};